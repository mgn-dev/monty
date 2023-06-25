#include "monty.h"

/**
 * count_tokens - counts the number of substrings that are
 * seperated by a charset of delimiters.
 * @str: string to evaluate.
 * @dlm: string of delimiters
 *
 * Return: number of tokens.
*/
int count_tokens(const char *str, const char *dlm)
{
	int i = 0, count = 0;
	short istoken;

	if (str == NULL || dlm == NULL)
		return (0);

	istoken = _strchr(dlm, str[i]) == 0 ? 0 : 1;

	while (str[i] != '\0')
	{
		if (_strchr(dlm, str[i]) == 0)
		{
			if (istoken == 0)
				count++;
			istoken = 1;
		}
		else
		{
			istoken = 0;
		}
		i++;
	}

	return (count);
}


/**
 * _strchr -  finds the first occurrence of a specific character
 * in a given string.
 * @str: string from which to search.
 * @c: character to search
 *
 * Return: the matching character.
*/
int _strchr(const char *str, const char c)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}

	return (0);
}

/**
 * ext_tokens - extracts tokens from a string and stores
 * them inside an array.
 * @str: string from which to extract tokens.
 * @dlm: delimiter charset.
 *
 * Return: array of tokens
*/
char **ext_tokens(const char *str, const char *dlm)
{
	char **token_arr;
	int i = 0, j = 0, count_tok = count_tokens(str, dlm);

	if (str == NULL || dlm == NULL || count_tok == 0)
		return (NULL);
	token_arr = malloc(sizeof(char *) * (count_tok + 1));
	if (token_arr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		garbage_collector();
		exit(EXIT_FAILURE);
	}

	while (str[i] != '\0')
	{
		if (_strchr(dlm, str[i]) == 0)
		{
			int p = i, q = i, r = 0, token_size = 0;

			while (str[p] != '\0' && _strchr(dlm, str[p]) == 0)
				p++;
			token_size = p - i;
			extt_h(str, token_arr, &token_size, &j, &r, &q);
			i = p;
		}
		else
			i++;
	}
	token_arr[j] = NULL;
	return (token_arr);
}

/**
 * extt_h - helper function to ext_tokens function,
 * handles it's inner workings.
 * @str: pointer to str input.
 * @tarr: pointer to token_arr.
 * @tsize: pointer to token_size.
 * @j: pointer to j.
 * @r: pointer to r.
 * @q: pointer to q.
 *
*/
void extt_h(const char *str, char **tarr, int *tsize, int *j, int *r, int *q)
{
	if (*tsize > 0)
	{
		(tarr[*j]) = malloc((*tsize) + 1);
		if ((tarr[*j]) == NULL)
		{
			free_2d(tarr);
			fprintf(stderr, "Error: malloc failed\n");
			garbage_collector();
			exit(EXIT_FAILURE);
		}
		while (*r < *tsize)
		{
			(tarr[*j][*r]) = (str[*q]);
			(*r)++;
			(*q)++;
		}

		(tarr[*j][*r]) = '\0';
		(*j)++;
	}
}
