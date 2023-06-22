#include "monty.h"

/**
* interpret - function that selects the correct function to
* perform the operation asked by the user.
* @ins: line instruction.
* @arg: line argument.
* @l: line number.
*
* Return: pointer to corresponding function.
*/
void (*interpret(char *ins, char *arg, int l))(stack_t **s, unsigned int l)
{
	int i = 0;

	instruc instr[] = {
		{{"push", push}, 1},
		{{"pall", pall}, 0},
		{{NULL, NULL}, 0}
	};

	while (ins != NULL && instr[i].ins.opcode != NULL)
	{
		if (strcmp(ins, instr[i].ins.opcode) == 0)
		{
			break;
		}

		i++;
	}

	if (ins != NULL && instr[i].ins.opcode == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", l, ins);
		garbage_collector();
		exit(EXIT_FAILURE);
	}

	if (instr[i].arg == 1 && (arg == NULL || is_number(arg) == 0))
	{
		fprintf(stdout, "L%i: usage: push integer\n", l);
		garbage_collector();
		exit(EXIT_FAILURE);
	}

	if (instr[i].arg == 1 && arg != NULL)
	{
		gob.n = atoi(arg);
	}

	return (instr[i].ins.f);
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
