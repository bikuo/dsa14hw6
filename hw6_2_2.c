#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl_ntudsa.h"

typedef struct score{
	int s[5];
	char id[21];
}Score;

void ranking(struct avl_node *node, int rank){
	if(node==NULL) 
        return;
	if(node->avl_cnode[1] + 1 == rank){
		printf("%s\n", ((Score*)node->avl_data)->id);
		return;
	}
		else if(node->avl_cnode[1] + 1 < rank)
			ranking(node->avl_link[0], rank-(node->avl_cnode[1])-1);
		else if(node->avl_cnode[1] + 1 > rank)
			ranking(node->avl_link[1],rank);
		return;
}

int int_compare(const void *pa, const void *pb, void *param){
	Score *a=(Score*)pa;
	Score *b=(Score*)pb;
	int avg1=(a->s[0]+a->s[1]+a->s[2]+a->s[3]+a->s[4])/5;
	int avg2=(b->s[0]+b->s[1]+b->s[2]+b->s[3]+b->s[4])/5;
	if(avg1>avg2)
		return 1;
	else if(avg1<avg2)
		return -1;
	else{
		if(a->s[1] > b->s[1])
			return 1;
		else if(b->s[1] > a->s[1])
			return -1;
		else{
			if(a->s[2] > b->s[2])
				return 1;
			else if(b->s[2] > a->s[2])
				return -1;
			else{
				if(a->s[4] > b->s[4])
					return 1;
				else if(b->s[4] > a->s[4])
					return -1;
				else{
					if(a->s[3] > b->s[3])
						return 1;
					else if(b->s[3] > a->s[3])
						return -1;
					else{
						if(a->s[0] > b->s[0])
							return 1;
						else if(b->s[0] > a->s[0])
							return -1;
						else{	
							if(strcmp(a->id,b->id) > 0)
								return -1;
							else if(strcmp(a->id,b->id) < 0)
								return 1; 
						}}}}}}}

int main(){
	struct avl_table *tree2;
	tree2 = avl_create(int_compare, NULL, NULL);
	char op[10],stu[21];
	int sc1,sc2,sc3,sc4,sc5,rank;
	while(scanf("%s",op) != EOF){
		if(op[0] == 'p'){
			Score* ele = (Score*)malloc(sizeof(Score));
			scanf("%s %d %d %d %d %d", ele->id,&sc1,&sc2,&sc3,&sc4,&sc5);
			ele->s[0] = sc1;
			ele->s[1] = sc2;
			ele->s[2] = sc3;
			ele->s[3] = sc4;
			ele->s[4] = sc5;
			void **p2 = avl_probe(tree2, ele);
			//printf("%d---%d\n", tree2->avl_root->avl_cnode[0] , tree2->avl_root->avl_cnode[1]);
		}
		else if(op[0] == 's'){
			scanf("%d",&rank);
			ranking(tree2->avl_root,rank);
		}
	}
	return 0;
}
