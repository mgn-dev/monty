#include "monty.h"

/**
 * add_to_head - function that adds an node to the head of
 * the stack_t linked list.
 * @head: pointer to the linked list.
 *
*/
void add_to_head(stack_t **head)
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

		new_node->n = atoi(gob.arg);
		new_node->next = *head;
		new_node->prev = NULL;
		(*head)->prev = new_node;
		*head = new_node;
	}
}
