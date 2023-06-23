#include "monty.h"

/**
 * add_to_tail - function that adds an node to the tail of
 * the stack_t linked list.
 * @head: pointer to the linked list.
 *
*/
void add_to_tail(stack_t **head)
{
	stack_t *new_node = NULL;

	if (*head == NULL)
	{
		new_node = malloc(sizeof(stack_t));

		if (new_node == NULL)
			return;

		new_node->n = atoi(gob.arg);
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		new_node = malloc(sizeof(stack_t));

		if (new_node == NULL)
			return;

		while ((*head)->next != NULL)
			*head = (*head)->next;

		new_node->n = atoi(gob.arg);
		new_node->prev = *head;
		new_node->next = NULL;
		(*head)->next = new_node;

		while ((*head)->prev != NULL)
			*head = (*head)->prev;
	}
}
