#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @head: pointer to the linked list.
 * @ln: instruction line number.
 *
*/
void add(stack_t **head, unsigned int ln)
{
	stack_t *temp = NULL;
	int a, b;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", ln);
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

	(*head)->n = (a + b);
}
