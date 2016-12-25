/* C code for Circular Linked list by Codingstreet.com */
#include<stdio.h>
#include<stdlib.h>
struct clnode {
	int		val;
	struct clnode  *next;
};
int
circular_length(struct clnode **head)
{
	int		count = 0;
	struct clnode  *tmp;
	tmp = (*head);
	if (tmp == NULL)
		return 0;
	do {
		tmp = tmp->next;
		count++;
	} while (tmp != (*head));
	return count;
}
int
create_clnode(int val, struct clnode **node)
{
	struct clnode  *tmp;
	tmp = malloc(sizeof(struct clnode));
	if (tmp == NULL)
		return 0;
	tmp->val = val;
	tmp->next = NULL;
	(*node) = tmp;
	return 1;
}
void
print_cl(struct clnode **head)
{
	struct clnode  *tmp;
	tmp = (*head);
	if (tmp == NULL)
		return;
	do {
		printf(" %d ", tmp->val);
		tmp = tmp->next;
	} while (tmp != (*head));
}
void
insert_clnode(struct clnode **head, struct clnode **node)
{
	if ((*head) == NULL) {
		(*node)->next = (*node);
		(*head) = (*node);
		return;
	} else {
		struct clnode  *tmp;
		tmp = (*head);
		while (tmp->next != (*head)) {
			tmp = tmp->next;
		}
		tmp->next = (*node);
		(*node)->next = (*head);
	}
}
void
insert_atbeginclnode(struct clnode **head, struct clnode **node)
{
	if ((*head) == NULL) {
		(*node)->next = (*node);
		(*head) = (*node);
		return;
	} else {
		struct clnode  *tmp;
		tmp = (*head);
		while (tmp->next != (*head)) {
			tmp = tmp->next;
		}
		tmp->next = (*node);
		(*node)->next = (*head);
		(*head) = (*node);
	}
}
void
delete_frontclnode(struct clnode **head)
{
	struct clnode  *tmp, *crnt;
	if ((*head) == NULL)
		return;
	tmp = (*head);
	crnt = (*head)->next;
	if (crnt == (*head)) {
		free(tmp);
		(*head) = NULL;
		return;
	}
	while (crnt->next != (*head))
		crnt = crnt->next;
	(*head) = (*head)->next;
	crnt->next = (*head);
	free(tmp);
}
void
delete_rearclnode(struct clnode **head)
{
	struct clnode  *tmp, *prev;;
	if ((*head) == NULL)
		return;
	tmp = (*head);
	prev = tmp;
	while (tmp->next != (*head)) {
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == (*head))
		(*head) = NULL;
	tmp->next = NULL;
	free(tmp);
	prev->next = (*head);
}

int
main()
{
	struct clnode  *head = NULL, *node = NULL;
	int		key       , ival;
	do {
		printf("\n*********** Circular List Menu ***********");
		printf("\n[1] Insert value");
		printf("\n[2] Print Circular List ");
		printf("\n[3] Print Length of list ");
		printf("\n[4] Insert at Begining ");
		printf("\n[5] Delete front node ");
		printf("\n[6] Delete rear node ");
		printf("\n[7] Exit ");
		printf("\nEnter the input key : ");
		scanf("%d", &key);
		switch (key) {
		case 1:
			printf("\n Enter the value to be inserted :");
			scanf("%d", &ival);
			if (create_clnode(ival, &node))
				insert_clnode(&head, &node);
			else
				printf("\n Memory is Full !! ");
			break;
		case 2:
			printf("\n Circular List contents are :\n");
			print_cl(&head);
			break;
		case 3:
			printf("\n Lenght = %d ", circular_length(&head));
			break;
		case 4:
			printf("\n Enter the value to be inserted :");
			scanf("%d", &ival);
			if (create_clnode(ival, &node))
				insert_atbeginclnode(&head, &node);
			else
				printf("\n Memory is Full !! ");
			break;
		case 5:
			delete_frontclnode(&head);
			break;
		case 6:
			delete_rearclnode(&head);
			break;
		case 7:
			break;

		default:
			printf("\t Enter the Correct key !!!!! ");
			break;
		}
	} while (key != 7);

	return 0;
}
