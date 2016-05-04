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
preorder(struct Tnode **Troot)
{
	if ((*Troot) != NULL) {
		printf(" %d ", (*Troot)->val);
		preorder(&((*Troot)->left));
		preorder(&((*Troot)->right));
	}
}
void 
postorder(struct Tnode **Troot)
{
	if ((*Troot) != NULL) {
		postorder(&((*Troot)->left));
		postorder(&((*Troot)->right));
		printf(" %d ", (*Troot)->val);
	}
}
void 
inorder(struct Tnode **Troot)
{
	if ((*Troot) != NULL) {
		inorder(&((*Troot)->left));
		printf(" %d ", (*Troot)->val);
		inorder(&((*Troot)->right));
	}
}

int 
main()
{
	struct Tnode   *root = NULL, *node;
	int		key       , ival;
	do {
		printf("\n[1] Insert value");
		printf("\n[2] Print Tree (Preorder) ");
		printf("\n[3] Print Tree (inorder) ");
		printf("\n[4] Print Tree (postorder) ");
		printf("\n[5] Exit ");
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
			printf("\n Tree contents are :\n");
			preorder(&root);
			break;
		case 3:
			printf("\n Tree contents are :\n");
			inorder(&root);
			break;
		case 4:
			printf("\n Tree contents are :\n");
			postorder(&root);
			break;
		case 5:
			break;
		default:
			printf("\t Enter the Correct key !!!!! ");
			break;
		}
	} while (key != 5);

	printf("\n Thank you for using codingstreet.com 's datastructure solution ");
	return 0;
}