#include "monty.h"

/**
 * pchar - function that prints the char at top of the stack.
 * @h: pointer to the linked list.
 * @ln: instruction line number.
 *
*/
void pchar(stack_t **h, unsigned int ln)
{
	stack_t *temp = NULL;
	(void)ln;

	temp = *h;

	if (temp == NULL)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", ln);
		garbage_collector();
		exit(EXIT_FAILURE);
	}

	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%i: can't pchar, value out of range\n", ln);
		garbage_collector();
		exit(EXIT_FAILURE);
	}

	if (temp->prev == NULL)
	{
		fprintf(stdout, "%c\n", temp->n);
	}
}
