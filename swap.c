#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @head: pointer to the linked list.
 * @ln: instruction line number.
 *
*/
void swap(stack_t **head, unsigned int ln)
{
	stack_t *temp = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", ln);
		garbage_collector();
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = (*head)->next;

	(*head)->prev = temp->prev;
	temp->next = (*head)->next;

	temp->prev = *head;

	if ((*head)->next != NULL)
		(*head)->next->prev = temp;

	(*head)->next = temp;
}
