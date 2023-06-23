#include "monty.h"

/**
 * mod - moddes the top two elements of the stack.
 * @head: pointer to the linked list.
 * @ln: instruction line number.
 *
*/
void mod(stack_t **head, unsigned int ln)
{
	stack_t *temp = NULL;
	int a, b;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", ln);
		garbage_collector();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", ln);
		garbage_collector();
		exit(EXIT_FAILURE);
	}

	a = (*head)->n;
	b = (*head)->next->n;

	temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	temp->next = NULL;
	free(temp);
	temp = NULL;

	(*head)->n = (b % a);
}
