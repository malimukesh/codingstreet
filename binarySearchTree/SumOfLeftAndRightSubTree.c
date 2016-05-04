/* Binary Search tree code by condingstreet.com */
#include<stdio.h>
#include<stdlib.h>
struct Tnode {
	int		val;
	struct Tnode   *left, *right;
};
int 
create_node(int val, struct Tnode **node)
{
	struct Tnode   *tmp;
	tmp = malloc(sizeof(struct Tnode));
	if (tmp == NULL)
		return 0;
	tmp->val = val;
	tmp->left = NULL;
	tmp->right = NULL;
	(*node) = tmp;
	return 1;
}
void 
insert_node(struct Tnode **Troot, struct Tnode **node)
{
	struct Tnode   *parent, *tmp;
	int		val;
	if ((*node) == NULL)
		return;
	if ((*Troot) == NULL) {
		(*Troot) = (*node);
		return;
	}
	tmp = (*Troot);
	val = (*node)->val;
	while (tmp != NULL) {
		parent = tmp;
		if (val < tmp->val)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	if (val < parent->val) {
		parent->left = (*node);
	} else
		parent->right = (*node);
	return;
}
void 
branchsum(struct Tnode **Troot, int **sum)
{
	if ((*Troot) != NULL) {
		branchsum(&((*Troot)->left), sum);
		(**sum) = (**sum) + (*Troot)->val;
		branchsum(&((*Troot)->right), sum);
	}
}
int 
main()
{
	struct Tnode   *root = NULL, *node;
	int		key       , ival, *sum, ssum = 0;
	sum = &ssum;
	do {
		printf("\n[1] Insert value");
		printf("\n[2] Left Branch Sum ");
		printf("\n[3] Right Branch Sum ");
		printf("\n[4] Exit ");
		printf("\nEnter the input key : ");
		scanf("%d", &key);
		switch (key) {
		case 1:
			printf("\n Enter the value to be inserted :");
			scanf("%d", &ival);
			if (create_node(ival, &node))
				insert_node(&root, &node);
			else
				printf("\n Memory is Full !! ");
			break;
		case 2:
			*sum = 0;
			if (root != NULL) {
				branchsum(&(root->left), &sum);
				printf("\n Left Branch Sum = %d", *sum);
			} else
				printf("\n Enter some value in tree");
			break;
		case 3:
			*sum = 0;
			if (root != NULL) {
				branchsum(&(root->right), &sum);
				printf("\n Right Branch Sum = %d", *sum);
			} else
				printf("\n Enter some value in tree");
			break;
		case 4:
			break;
		default:
			printf("\t Enter the Correct key !!!!! ");
			break;
		}
	} while (key != 4);

	printf("\n Thank you for using codingstreet.com 's datastructure solution ");
	return 0;
}