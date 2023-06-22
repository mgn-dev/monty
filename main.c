#include "monty.h"
#include <stdio.h>
#include <fcntl.h>

/**
 * main - entry point to the monty interpreter.
 * @argc: number of args
 * @argv: pointer on args
 *
 * Return: 0 on Success,
 */
int main(int argc, char *argv[])
{
	size_t buff_size  = 0;
	char *buffer = NULL, **command = { NULL };
	FILE *fp;
	int line = 0;
	stack_t *head = NULL;
	void (*execute)(stack_t **stack, unsigned int ln);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	gob.fp = &fp;
	gob.buff_ptr = &buffer;
	gob.cmd_ptr = &command;
	gob.stack_ptr = &head;

	while (getline(&buffer, &buff_size, fp) != -1)
	{
		line++;
		command = parse(buffer);
		execute = interpret(command[0], command[1], line);
		execute(&head, line);
		free_2d(command);
	}

	free_dl_list(head);
	free(buffer);
	fclose(fp);

	return (0);
}
