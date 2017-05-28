#include<stdio.h>
#include<stdlib.H>
struct Tnode {
	int val;
	struct Tnode *left;
	struct Tnode *right;
};

struct Tnode *create_node(int val)
{
	struct Tnode *tmp;
	tmp = malloc(sizeof(struct Tnode));

	tmp->val = val;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}

int find_index_of(int A[], int val, int start_index, int end_index)
{
	int i;

	for (i=start_index; i<=end_index; i++) {
		if (A[i]==val) return i;
	}

	return -1;
};

struct Tnode *build_tree(int in_order [], int pre_order[], int *pre_order_index, int in_start, int in_end)
{

	struct Tnode *node;

	if (in_start > in_end) return NULL;
	(*pre_order_index)+=1;
	node   =  create_node(pre_order[*pre_order_index-1]);
	if (in_start == in_end) { return node; }

	int in_order_index = find_index_of(in_order, node->val, in_start, in_end);

	node->left = build_tree(in_order, pre_order, pre_order_index, in_start, in_order_index-1);
	node->right = build_tree(in_order, pre_order, pre_order_index, in_order_index+1, in_end);

	return node;
}

void inorder(struct Tnode *troot)
{
	if (troot!=NULL) {
		inorder(troot->left);
		printf(" %d ", troot->val);
		inorder(troot->right);
	}
}

int main()
{
	int in[]  = {4,2,5,1,6,3};
	int pre[] = {1,2,4,5,3,6};

	struct Tnode *troot;
	int s = 0;
	troot = build_tree(in,pre,&s,0,5);
	inorder(troot);

	return 0;
}