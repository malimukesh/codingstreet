/* Queue using linked list in C. C code by codingstreet.com */
#include<stdio.h>
#include<stdlib.h>
struct snode {
	int		val;
	struct snode   *next;
};
void 
enqueue_sll(int val, struct snode **qhead, struct snode **qtail)
{
	struct snode   *tmp;
	if ((*qhead) == NULL) {
		tmp = malloc(sizeof(struct snode));
		tmp->val = val;
		tmp->next = NULL;
		(*qhead) = tmp;
		(*qtail) = tmp;
	} else {
		tmp = malloc(sizeof(struct snode));
		tmp->val = val;
		tmp->next = NULL;
		(*qtail)->next = tmp;
		(*qtail) = tmp;
	}
}
void 
dequeue_sll(struct snode **qhead)
{
	struct snode   *tmp;
	if ((*qhead) == NULL)
		return;
	tmp = (*qhead);
	(*qhead) = (*qhead)->next;
	tmp->next = NULL;
	free(tmp);
}
void 
print_queue(struct snode **qhead)
{
	struct snode   *tmp;
	tmp = (*qhead);
	while (tmp != NULL) {
		printf(" %d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
}
int 
is_queue_empty(struct snode **qhead)
{
	if ((*qhead) == NULL)
		return 1;
	else
		return 0;
}
int 
main()
{
	struct snode   *qh1 = NULL, *qt1 = NULL;
	int		key       , val;
	do {
		printf("******* Queue by SLL Menu ******\n");
		printf("C Code by codingstreet.com \n");
		printf("[1] Enqueue \n");
		printf("[2] Dequee \n");
		printf("[3] PRINT Queue \n");
		printf("[4] IS QUEUE EMPTY\n");
		printf("[5] Exit \n");
		printf("Enter the key : ");
		scanf("%d", &key);
		switch (key) {
		case 1:
			printf("Enter the value : ");
			scanf("%d", &val);
			enqueue_sll(val, &qh1, &qt1);
			break;
		case 2:
			if (is_queue_empty(&qh1) != 1) {
				dequeue_sll(&qh1);
			} else
				printf("\n\t\t Can't dequeue because Queue is Empty !!! \n");
			break;
		case 3:
			printf("\n Queue Contents are : \n ");
			print_queue(&qh1);
			break;
		case 4:
			if (is_queue_empty(&qh1) == 1) {
				printf("\n Queue is Empty \n");
			} else
				printf("\n Queue is Not Empty \n");
			break;
		case 5:
			break;
		default:
			printf("\n Enter the Valid key .. . .");
		}
	} while (key != 5);
	printf("\n Thanks for using codingstreet.com's Data structure solutions ");
	return 0;
}