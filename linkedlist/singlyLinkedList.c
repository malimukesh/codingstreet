/* Singly Linked List code by Codingstreet.com */
#include<stdio.h>
#include<stdlib.h>
struct snode {
	int		val;
	struct snode   *next;
};
int 
create_snode(int val, struct snode **node)
{
	struct snode   *tmp;
	tmp = malloc(sizeof(struct snode));
	if (tmp == NULL)
		return 0;
	tmp->val = val;
	tmp->next = NULL;
	*node = tmp;
	return 1;
}
int 
insert_snode(struct snode **head, struct snode **node)
{
	if ((*head) == NULL) {
		(*head) = (*node);
		(*head)->next = NULL;
	} else {
		struct snode   *root;
		root = (*head);
		struct snode   *next, *prev, *tmp;
		next = root->next;
		prev = tmp = root;
		while (next != NULL) {
			prev = tmp;
			tmp = tmp->next;
			next = tmp;
		} prev->next = (*node);
		next = prev->next;
		next->next = NULL;
	} return 1;
}
struct snode   *
find_snode(struct snode **head, int val)
{
	struct snode   *root;
	root = *head;
	if (root == NULL) {
		return NULL;
	} else if (root->val == val) {
		return root;
	} else {
		struct snode   *tmp;
		tmp = root;
		while (tmp != NULL) {
			if (tmp->val == val) {
				return tmp;
			} tmp = tmp->next;
		} return tmp;
	}
}
int 
delete_snode(struct snode **head, struct snode **node)
{
	struct snode   *root, *tmp, *next, *prev, *dlnode;
	root = *head;
	dlnode = *node;
	if (root == NULL) {
		return 0;
	} else if (root == dlnode) {
		next = root->next;
		root->next = NULL;
		free(root);
		root = next;
		*head = root;
		return 1;
	} else {
		tmp = *head;
		next = tmp->next;
		prev = tmp;
		while (tmp != NULL) {
			if (tmp == dlnode) {
				prev->next = tmp->next;
				tmp->next = NULL;
				free(tmp);
				return 1;
			} prev = tmp;
			tmp = tmp->next;
		} return 0;
	}
}
void 
print_sll(struct snode **head)
{
	struct snode   *tmp;
	tmp = (*head);
	while (tmp != NULL) {
		printf(" %d ", tmp->val);
		tmp = tmp->next;
	}
}
void 
reverse_sll(struct snode **head)
{
	if ((*head) == NULL)
		return;
	if ((*head)->next == NULL)
		return;
	struct snode   *next, *prev, *curnt;
	curnt = (*head)->next;
	prev = *head;
	prev->next = NULL;
	next = curnt->next;
	while (next != NULL) {
		curnt->next = prev;
		prev = curnt;
		curnt = next;
		next = next->next;
	} curnt->next = prev;
	(*head) = curnt;
}
struct snode   *findnthnode(struct snode **head, int lpo){
	struct snode   *tmp = (*head), *ptmp;
	ptmp = (*head);
	int		i = 0;
	while (tmp != NULL) {
		i++;
		tmp = tmp->next;
		if (i > lpo)
			ptmp = ptmp->next;
	} if (lpo > i)
		return NULL;
	return ptmp;
}
int 
main()
{
	struct snode   *head = NULL, *node = NULL;
	int		val       , ival;
	do {
		printf("\n Singly Linked List Menu : \n");
		printf("[1] Insert Node: \n");
		printf("[2] Delete Node: \n");
		printf("[3] Print Node: \n");
		printf("[4] Reverse List:\n");
		printf("[5] Find Nth node from Last : \n");
		printf("[6] Exit: \n");
		printf("Enter the input:");
		scanf("%d", &val);
		switch (val) {
		case 1:
			printf("\n Enter the Val :");
			scanf("%d", &ival);
			if (create_snode(ival, &node)) {
				insert_snode(&head, &node);
			} else
				printf("!!!@@@ System is outof Memory @@@!!!\n");
			break;
		case 2:
			printf("\n Delete the Val :");
			scanf("%d", &ival);
			node = find_snode(&head, ival);
			if (node != NULL) {
				delete_snode(&head, &node);
			} else
				printf(" The Node Value not found \n");
			break;
		case 3:
			printf("\n The Singly List is : \n");
			print_sll(&head);
			break;
		case 4:
			reverse_sll(&head);
			break;
		case 5:
			node = NULL;
			printf("\n Enter the position fro last : ");
			scanf("%d", &ival);
			node = findnthnode(&head, ival);
			if (node == NULL)
				printf("\n Wrong Input position ");
			else
				printf("\n %d ", node->val);
			break;
		case 6:
			break;
		default:
			printf("===> [ Enter the Correct input] <==== \n");
			break;
		}
	} while (val != 6);
	printf(" \n[Thank you!! for using codingstreet.com 's Data Structure Solutions !!] \n\n");
	return 0;
}
