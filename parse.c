#include "monty.h"

/**
 * parse - extracts sub-strings from a string
 * seperated by specified delimiters.
 * @in_str: the string read from input.
 *
 * Return: an array of strings (tokens);
*/
char **parse(char *in_str)
{
	char *delimiters = " \n\0";
	char **token_arr = { NULL };

	token_arr = ext_tokens(in_str, delimiters);

	if (token_arr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		garbage_collector();
		exit(EXIT_FAILURE);
	}

	return (token_arr);
}
