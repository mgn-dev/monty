#include "monty.h"

/**
 * pstr - function that prints the stack_t linked list
 * from last to first.
 * @h: pointer to the linked list.
 * @ln: instruction line number.
 *
*/
void pstr(stack_t **h, unsigned int ln)
{
	stack_t *temp = NULL;
	(void)ln;

	temp = *h;

	if (temp == NULL)
	{
		fprintf(stdout, "\n");
		return;
	}

	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
		{
			fprintf(stdout, "\n");
			break;
		}

		fprintf(stdout, "%c", temp->n);
		temp = temp->next;
	}
}
