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
	short istoken = _strchr(dlm, str[i]) == 0 ? 0 : 1;

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
	int i = 0, j = 0;

	if (str == NULL || dlm == NULL)
		return (NULL);
	token_arr = malloc(sizeof(char *) * (count_tokens(str, dlm) + 1));
	if (token_arr == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		if (_strchr(dlm, str[i]) == 0)
		{
			int p = i, q = i, r = 0, token_size = 0;

			while (str[p] != '\0' && _strchr(dlm, str[p]) == 0)
				p++;
			token_size = p - i;
			if (token_size > 0)
			{
				token_arr[j] = malloc(token_size + 1);
				if (token_arr[j] == NULL)
				{
					free_2d(token_arr);
					return (NULL);
				}
				while (r < token_size)
					token_arr[j][r++] = str[q++];
				token_arr[j][r] = '\0';
				j++;
			}
			i = p;
		}
		else
			i++;
	}
	token_arr[j] = NULL;
	return (token_arr);
}
