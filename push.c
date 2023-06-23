#include "monty.h"

/**
 * push - function that adds an node to the end of
 * the stack_t linked list.
 * @head: pointer to the linked list.
 * @ln: instruction line number.
 *
*/
void push(stack_t **head, unsigned int ln)
{
	if (gob.arg == NULL || is_number(gob.arg) == 0)
	{
		fprintf(stderr, "L%i: usage: push integer\n", ln);
		garbage_collector();
		exit(EXIT_FAILURE);
	}

	if (gob.mode == QUEUE)
	{
		add_to_tail(head);
	}
	else
	{
		add_to_head(head);
	}
}
