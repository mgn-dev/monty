#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFF_MAX 1024
#define QUEUE 1
#define STACK 0

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
 * struct global_obj - opcode and its function
 * @mode: argument given to opcode.
 * @arg: argument given to opcode.
 * @fp: pointer to FILE pointer
 * @cmd_ptr: pointer to command pointer.
 * @stack_ptr: pointer to stack dllist.
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct global_obj
{
	int mode;
	char *arg;
	FILE **fp;
	char ***cmd_ptr;
	stack_t **stack_ptr;
} global_obj;

global_obj gob;

int count_tokens(const char *str, const char *dlm);
int is_number(char *str);
int _strchr(const char *str, const char c);
char **ext_tokens(const char *str, const char *dlm);
void extt_h(const char *str, char **tarr, int *tsze, int *j, int *r, int *q);
char **parse(char *in_str);
void garbage_collector(void);
void free_2d(char **grid);
void free_dl_list(stack_t *head);

void (*interpret(char *ins, int l))(stack_t **s, unsigned int l);
void push(stack_t **stack, unsigned int ln);
void pall(stack_t **stack, unsigned int ln);
void pint(stack_t **stack, unsigned int ln);
void pop(stack_t **stack, unsigned int ln);
void swap(stack_t **stack, unsigned int ln);
void add(stack_t **stack, unsigned int ln);
void nop(stack_t **stack, unsigned int ln);
void sub(stack_t **stack, unsigned int ln);
void divi(stack_t **stack, unsigned int ln);
void mul(stack_t **stack, unsigned int ln);
void mod(stack_t **stack, unsigned int ln);
void pchar(stack_t **stack, unsigned int ln);
void pstr(stack_t **stack, unsigned int ln);
void rotl(stack_t **stack, unsigned int ln);
void rotr(stack_t **stack, unsigned int ln);
void queue(stack_t **stack, unsigned int ln);
void stack(stack_t **stack, unsigned int ln);
void add_to_head(stack_t **head);
void add_to_tail(stack_t **head);

#endif
