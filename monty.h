#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFF_MAX 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct instruc - opcode and its function
 * @ins: the opcode
 * @arg: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruc
{
	instruction_t ins;
	short arg;
} instruc;

/**
 * struct global_obj - opcode and its function
 * @n: argument given to opcode.
 * @fp: pointer to FILE pointer
 * @cmd_ptr: pointer to command pointer.
 * @stack_ptr: pointer to stack dllist.
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct global_obj
{
	int n;
	FILE **fp;
	char ***cmd_ptr;
	stack_t **stack_ptr;
} global_obj;

global_obj gob;

int count_tokens(const char *str, const char *dlm);
int is_number(char *str);
int _strchr(const char *str, const char c);
char **ext_tokens(const char *str, const char *dlm);
char **parse(char *in_str);
void garbage_collector(void);
void free_2d(char **grid);
void free_dl_list(stack_t *head);

void (*interpret(char *ins, char *arg, int l))(stack_t **s, unsigned int l);
void push(stack_t **stack, unsigned int ln);
void pall(stack_t **stack, unsigned int ln);

#endif
