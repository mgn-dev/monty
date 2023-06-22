#include "monty.h"

/**
 * pint - function that prints top of the stack.
 * @h: pointer to the linked list.
 * @ln: instruction line number.
 *
*/
void pint(stack_t **h, unsigned int ln)
{
	stack_t *temp = NULL;
	(void)ln;

	temp = *h;

	if (temp == NULL)
		return;

	if (temp->prev == NULL)
	{
		fprintf(stdout, "%i\n", temp->n);
	}
}
