#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @head: pointer to the linked list.
 * @ln: instruction line number.
 *
*/
void pop(stack_t **head, unsigned int ln)
{
	stack_t *temp = NULL;

	if (*head == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", ln);
		garbage_collector();
		exit(EXIT_FAILURE);
	}

	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		temp = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		temp->next = NULL;
		free(temp);
	}
}
