#include "monty.h"

/**
 * garbage_collector - garbage collection.
 *
*/
void garbage_collector(void)
{
	if (*gob.buff_ptr != NULL)
	{
		free(*gob.buff_ptr);
	}

	free_2d(*gob.cmd_ptr);

	if (*gob.fp != NULL)
	{
		fclose(*gob.fp);
	}

	if (*gob.stack_ptr != NULL)
	{
		free_dl_list(*gob.stack_ptr);
	}
}

/**
* free_2d - frees a two dimensional array.
* @grid: 2d array
*
*/
void free_2d(char **grid)
{
	int i = 0, len = 0;

	while (grid[i++] != NULL)
		len++;

	for (i = 0; i < len; i++)
	{
		free(grid[i]);
	}

	free(grid);

	grid = NULL;
}

/**
 * free_dl_list - function that frees a doubly linked list.
 * @head: pointer to head of dlistint_t list.
 *
 */
void free_dl_list(stack_t *head)
{
	if (head == NULL)
		return;

	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}

	free(head);

	head = NULL;
}
