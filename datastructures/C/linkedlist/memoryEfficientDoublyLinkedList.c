/* C Code for Memory Efficient Doubly linked list by Codingstreet.com */
#include<stdio.h>
#include<stdlib.h>
struct ednode {
	int		val;
	struct ednode  *ptr;
};
int 
create_ednode(int val, struct ednode **node)
{
	struct ednode  *tmp;
	tmp = malloc(sizeof(struct ednode));
	if (tmp == NULL)
		return 0;
	tmp->val = val;
	tmp->ptr = NULL;
	(*node) = tmp;
	return 1;
}
void 
insert_ednode(struct ednode **head, struct ednode **node, struct ednode **tail)
{
	struct ednode  *prev, *next, *tmp;
	if ((*head) == NULL && (*tail) == NULL) {
		(*head) = (*tail) = (*node);
		(*head)->ptr = NULL;
	} else if ((*head)->ptr == NULL) {
		next = (*node);
		(*head)->ptr = (struct ednode *)((unsigned int)(NULL) ^ (unsigned int)(next));
		next->ptr = (struct ednode *)((unsigned int)(*head) ^ (unsigned int)(NULL));
		(*tail) = (*node);
	} else {
		prev = (*tail);
		next = (*node);
		tmp = (struct ednode *)((unsigned int)(NULL) ^ (unsigned int)(prev));
		prev->ptr = (struct ednode *)((unsigned int)(tmp) ^ (unsigned int)(next));
		next->ptr = (struct ednode *)((unsigned int)(NULL) ^ (unsigned int)(prev));
		(*tail) = next;
	}

}
void 
print_ednode(struct ednode **head, struct ednode **tail)
{
	struct ednode  *tmp, *prev, *next;
	if ((*head) == NULL)
		return;
	tmp = (*head);
	prev = NULL;
	while (tmp != (*tail)) {
		printf(" %d ", tmp->val);
		tmp = (struct ednode *)((unsigned int)(tmp->ptr) ^ (unsigned int)(prev));
		prev = tmp;
	}
	printf(" %d ", tmp->val);
}
void 
printrev_ednode(struct ednode **head, struct ednode **tail)
{
	struct ednode  *tmp, *prev, *next;
	if ((*head) == NULL)
		return;
	tmp = (*tail);
	prev = NULL;
	while (tmp != (*head)) {
		printf(" %d ", tmp->val);
		tmp = (struct ednode *)((unsigned int)(tmp->ptr) ^ (unsigned int)(prev));
		prev = tmp;
	}
	printf(" %d ", tmp->val);
}
int 
main()
{
	printf("\n Efficient Doubly Linked List ");
	struct ednode  *head = NULL, *node = NULL, *tail = NULL, *prev = NULL,
	               *tmp;
	int		key       , ival;
	do {
		printf("\n************* Efficient Doubly Linked List Menu *************");
		printf("\n************* Coded by Codingstreet.com *************");
		printf("\n[1] Insert Node : ");
		printf("\n[2] Print List : ");
		printf("\n[3] print rev list : ");
		printf("\n[4] (Exit) ");
		printf("\nEnter the key : ");
		scanf("%d", &key);
		printf("\n");
		switch (key) {
		case 1:
			printf("\nEntet the input value ");
			scanf("%d", &ival);
			if (create_ednode(ival, &node))
				insert_ednode(&head, &node, &tail);
			else
				printf("\n System id out of Memory !! ");
			break;
		case 2:
			print_ednode(&head, &tail);
			break;
		case 3:
			printrev_ednode(&head, &tail);
			break;
		case 4:
			break;
		default:
			printf("\n Enter the VALID KEY [1,2,3,4] ");
			break;
		}
	} while (key != 4);
	printf("\n Thanks for using codingstreet.com 's Data structure solution ");
	return 0;
}