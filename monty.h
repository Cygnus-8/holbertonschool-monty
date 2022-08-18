#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

void open_file(char *file_name);
void read_line(FILE *fd);
int line_interpreter(char *lineptr, int line_number, int data_mode);
void search_func(char *opcode, char *value, int line_number, int data_mode);
void exec_fun(void (*f)(), char *opcode, char *value, int ln, int data_mode);

void more_error(int error_code, ...);
void error(int error_code, ...);

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

extern stack_t *head;
stack_t *create_node(int n);
void free_nodes(void);

void add_to_stack(stack_t **node_to_add, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **last, unsigned int ln);
void pop_func(stack_t **last, unsigned int line_number);
void swap_nodes(stack_t **stack, unsigned int line_number);
void add_nodes(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void mod_nodes(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
#endif
