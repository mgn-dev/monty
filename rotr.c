#include "monty.h"

/**
 * rotr - rotls the top two elements of the stack.
 * @head: pointer to the linked list.
 * @ln: instruction line number.
 *
*/
void rotr(stack_t **head, unsigned int ln)
{
	stack_t *temp = NULL;
	(void)ln;

	if (*head == NULL || ((*head)->next == NULL && (*head)->prev == NULL))
	{
		return;
	}

	temp = *head;

	while (temp->next != NULL)
		temp = temp->next;

	while ((*head)->prev != NULL)
		*head = (*head)->prev;

	temp->prev->next = NULL;
	temp->prev = NULL;

	temp->next = *head;
	(*head)->prev = temp;

	while ((*head)->prev != NULL)
		*head = (*head)->prev;
}
