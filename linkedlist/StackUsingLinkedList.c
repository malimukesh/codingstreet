/* Stack implementation by linked list in C from Codingstreet.com */
#include<stdio.h>
#include<stdlib.h>
struct snode {
	int		val;
	struct snode   *next;
};
void 
push_sstack(int val, struct snode **stack)
{
	struct snode   *stop, *tmp;
	stop = *stack;
	if (stop == NULL) {
		tmp = malloc(sizeof(struct snode));
		tmp->val = val;
		tmp->next = NULL;
		(*stack) = tmp;
	} else {
		tmp = malloc(sizeof(struct snode));
		if (tmp != NULL) {
			tmp->val = val;
			tmp->next = stop;
			(*stack) = tmp;
		} else
			printf(" \n Memory is Full Can't insert value\n ");
	}
}
void 
pop_sstack(struct snode **stack)
{
	if ((*stack) != NULL) {
		struct snode   *tmp, *stop;
		stop = (*stack);
		tmp = stop;
		stop = stop->next;
		*stack = stop;
		tmp->next = NULL;
		free(tmp);
	}
}
int 
is_stack_empty(struct snode **stack)
{
	if ((*stack) == NULL)
		return 1;
	else
		return 0;
}
void 
print_sstack(struct snode **stack)
{
	struct snode   *tmp;
	tmp = *stack;
	while (tmp != NULL) {
		printf(" %d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
}
int 
main()
{
	struct snode   *stack;
	int		key       , val;
	do {
		printf("******* Stack by SLL Menu ******\n");
		printf("[1] PUSH \n");
		printf("[2] POP \n");
		printf("[3] PRINT STACK \n");
		printf("[4] IS STACK EMPTY\n");
		printf("[5] Exit \n");
		printf("Enter the key : ");
		scanf("%d", &key);
		switch (key) {
		case 1:
			printf("Enter the value : ");
			scanf("%d", &val);
			push_sstack(val, &stack);
			break;
		case 2:
			if (is_stack_empty(&stack) != 1) {
				pop_sstack(&stack);
			} else
				printf("\n\t\t Can't Pop Value  stack is Empty !!! \n");
			break;
		case 3:
			printf("\n Stack Contents are : \n ");
			print_sstack(&stack);
			break;
		case 4:
			if (is_stack_empty(&stack) == 1) {
				printf("\n Stack is Empty \n");
			} else
				printf("\n Stack is Not Empty \n");
			break;
		case 5:
			break;
		default:
			printf("\n Enter the Valid key .. . .");
		}
	} while (key != 5);
	printf("\n Thankyou for using Codingstreet.com 's Data structure Solution ");
	return 0;
}