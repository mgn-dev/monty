#include "monty.h"

/**
* interpret - function that selects the correct function to
* perform the operation asked by the user.
* @ins: line instruction.
* @l: line number.
*
* Return: pointer to corresponding function.
*/
void (*interpret(char *ins, int l))(stack_t **s, unsigned int l)
{
	int i = 0;

	instruction_t instr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	while (ins != NULL && instr[i].opcode != NULL)
	{
		if (strcmp(ins, instr[i].opcode) == 0)
		{
			break;
		}

		i++;
	}

	if (ins != NULL && instr[i].opcode == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", l, ins);
		garbage_collector();
		exit(EXIT_FAILURE);
	}

	return (instr[i].f);
}


/**
 * is_number - checks if a string is a number.
 * @str: the string to check
 *
 * Return: 1 if true, 0 if false.
*/
int is_number(char *str)
{
	char *end_ptr;
	int result;

	strtol(str, &end_ptr, 10);

	if (*end_ptr == '\0')
		result = 1;
	else
		result = 0;

	return (result);
}
