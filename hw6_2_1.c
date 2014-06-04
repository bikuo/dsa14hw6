#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include "rb.h"
#include "bst.h"

void post_order_interger_avl(const struct avl_node *node){
	if(node == NULL)
		return;
	printf("%s ", ((char *)node->avl_data));
	if(node->avl_link[0] != NULL || node->avl_link[1] != NULL){
		putchar('(');
		post_order_interger_avl(node->avl_link[0]);
		putchar(',');
		putchar(' ');
		post_order_interger_avl(node->avl_link[1]);
		putchar(')');
	}
}

void post_order_interger_bst(const struct bst_node *node){
	if(node == NULL)
		return;
	printf("%s ", ((char *)node->bst_data));
	if(node->bst_link[0] != NULL || node->bst_link[1] != NULL){
		putchar('(');
		post_order_interger_bst(node->bst_link[0]);
		putchar(',');
		putchar(' ');
		post_order_interger_bst(node->bst_link[1]);
		putchar(')');
	}
}

void post_order_interger_rb(const struct rb_node *node){
	if(node == NULL)
		return;
	printf("%s ", ((char *)node->rb_data));
	if(node->rb_link[0] != NULL || node->rb_link[1] != NULL){
		putchar('(');
		post_order_interger_rb(node->rb_link[0]);
		putchar(',');
		putchar(' ');
		post_order_interger_rb(node->rb_link[1]);
		putchar(')');

	}
}

int int_compare(const void *pa, const void *pb, void *param){
	char *a,*b;
	a=(char*)pa;
	b=(char*)pb;
	if(strcmp(a,b)<0) return -1;
	else if(strcmp(a,b)>0) return +1;
	else return 0;
}

int main(){
	struct avl_table *tree2;
	struct rb_table *tree3;
	struct bst_table *tree1;
	tree1 = bst_create(int_compare, NULL, NULL);
	tree2 = avl_create(int_compare, NULL, NULL);
	tree3 = rb_create(int_compare, NULL, NULL);
	int i,j,k;
	char people[32][10]={"Chuang","Chou","Chang","Chao","Chen","Cheng","Chu","Fu","Fuh","Hsiang",
		"Hsu","Hsueh","Hung","Jang","Kao","Kuo","Lai","Lee","Liao","Lin","Liou","Liu","Lu",
	 	"Lyuu","Ouhyoung","Oyang","Shih","Tsai","Tseng","Wang","Wu","Yang"};
	for(i = 0; i < 32; ++i){
		char* ele = (char*)malloc(sizeof(char)*10);
		ele = people[i];
		void **p1 = bst_probe(tree1, ele);
		void **p2 = avl_probe(tree2, ele);
		void **p3 = rb_probe(tree3, ele);
	}
	post_order_interger_bst(tree1->bst_root);
	puts("");
	puts("\n");
	post_order_interger_avl(tree2->avl_root);
	puts("");
	puts("\n");
	post_order_interger_rb(tree3->rb_root);
	puts("");
	return 0;
}
