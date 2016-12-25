/* C Code for Doubly linked list by Codingstreet.com */
#include<stdio.h>
#include<stdlib.h>
struct dnode {
	int		val;
	struct dnode   *next, *prev;
};
int create_dnode(int val, struct dnode **node)
{
	struct dnode   *tmp;
	tmp = malloc(sizeof(struct dnode));
	if (tmp == NULL)
		return 0;
	tmp->val = val;
	tmp->next = NULL;
	tmp->prev = NULL;
	*node = tmp;
	return 1;
}
int 
insert_dnode(struct dnode **head, struct dnode **node)
{
	if ((*head) == NULL) {
		(*head) = (*node);
		(*head)->next = NULL;
		(*head)->prev = NULL;
	} else {
		struct dnode   *root;
		root = (*head);
		struct dnode   *next, *prev, *tmp;
		next = root->next;
		prev = tmp = root;
		while (next != NULL) {
			prev = tmp;
			tmp = tmp->next;
			next = tmp;
		} prev->next = (*node);
		(*node)->prev = prev;
		next = prev->next;
		next->next = NULL;
	} return 1;
} 
void print_dll(struct dnode **head)
{
	struct dnode   *tmp;
	tmp = (*head);
	while (tmp != NULL) {
		printf(" %d ", tmp->val);
		tmp = tmp->next;
	} printf("\n");
} 
void print_dll_reverse(struct dnode **head)
{
	struct dnode   *tmp;
	tmp = (*head);
	if (tmp == NULL)
		return;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	} while (tmp != NULL) {
		printf(" %d ", tmp->val);
		tmp = tmp->prev;
	} printf("\n");
} 
int delete_dnode(struct dnode **head, struct dnode **node)
{
	struct dnode   *root, *tmp, *next, *prev, *dlnode;
	root = *head;
	dlnode = *node;
	if (root == NULL) {
		return 0;
	} else if (root == dlnode && root->next == NULL) {
		free(root);
		*head = NULL;
	} else if (root == dlnode) {
		next = root->next;
		root->next = NULL;
		next->prev = NULL;
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
				tmp->next = prev;
				tmp->next = NULL;
				tmp->prev = NULL;
				free(tmp);
				return 1;
			} prev = tmp;
			tmp = tmp->next;
		} return 0;
	}
} 
struct dnode * find_dnode(struct dnode **head, int val)
{
	struct dnode   *root;
	root = *head;
	if (root == NULL) {
		return NULL;
	} else if (root->val == val) {
		return root;
	} else {
		struct dnode   *tmp;
		tmp = root;
		while (tmp != NULL) {
			if (tmp->val == val) {
				return tmp;
			} tmp = tmp->next;
		} return tmp;
	}
} int
main()
{
	struct dnode   *head = NULL, *node = NULL;
	int		val       , ival;
	do {
		printf("\n----------------------------------");
		printf("\n Doubly Linked List Menu : \n");
		printf("[1] Insert Node: \n");
		printf("[2] Delete Node: \n");
		printf("[3] Print List: \n");
		printf("[4] Print List Reverse : \n");
		printf("[5] Find Node :\n");
		printf("[6] Exit: \n");
		printf("Enter the input:");
		scanf("%d", &val);
		printf("----------------------------------\n");
		switch (val) {
		case 1:
			printf("\n Enter the Val :");
			scanf("%d", &ival);
			if (create_dnode(ival, &node)) {
				insert_dnode(&head, &node);
			} else
				printf("!!!@@@ System is outof Memory @@@!!!\n");
			break;
		case 2:
			printf("\n Delete the Val :");
			scanf("%d", &ival);
			node = find_dnode(&head, ival);
			if (node != NULL) {
				delete_dnode(&head, &node);
			} else
				printf(" The Node Value not found \n");
			break;
		case 3:
			printf("\n The Doubly List is : \n");
			print_dll(&head);
			break;
		case 4:
			print_dll_reverse(&head);
			break;
		case 5:
			printf("\n Enter the Val to Find:");
			scanf("%d", &ival);
			node = find_dnode(&head, ival);
			if (node == NULL)
				printf("\t *** Value Not Found !! ***\n");
			else
				printf("\t ** Value Found ***\n");
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