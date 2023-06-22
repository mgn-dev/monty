#include "monty.h"

/**
 * pall - function that prints the stack_t linked list
 * from last to first.
 * @h: pointer to the linked list.
 * @ln: instruction line number.
 *
*/
void pall(stack_t **h, unsigned int ln)
{
	stack_t *temp = NULL;
	(void)ln;

	temp = *h;

	if (temp == NULL)
		return;

	while (temp != NULL)
	{
		fprintf(stdout, "%i\n", temp->n);
		temp = temp->next;
	}
}
