#include "simple_shell.h"

/**
 * execute - executes a command in a new process
 * @in_arr: command and argument list.
 * @self: pointer arg[0] argument.
 * @env: environmental variables.
 * @cyc: number of executed cycles.
 *
 * Return: 1 on exit command 0 otherwise.
*/
int execute(char **in_arr, char *self, char **env, int cyc)
{
	if (in_arr == NULL)
		return (0);

	if (_strcmp(in_arr[0], "exit") != 0)
		handle_exit(in_arr);

	if (_strcmp(in_arr[0], "cd") != 0)
	{
		dir_changes(in_arr[1]);
		return (0);
	}

	if (_strcmp(in_arr[0], "env") != 0)
	{
		print_env(env);
		return (0);
	}

	execute_child(in_arr, self, env, cyc);

	return (0);
}
