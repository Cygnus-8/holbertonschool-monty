#include "monty.h"

/**
 * mod_nodes - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: Pointer of pointer that points to the top of the stack
 * @line_number: Line that contains the instruction
 */

void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(3, line_number);

	if ((*stack)->n == 0)
		more_error(4, line_number);

	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * print_char - prints the char at the top of the stack, followed by a new line
 * @stack: Pointer of pointer that points to the top of the stack
 * @line_number: Line that contains the instruction
 */

void print_char(stack_t **stack, unsigned int line_number)
{
	int val_ascii;

	if (stack == NULL || *stack == NULL)
		more_error(6, line_number);

	val_ascii = (*stack)->n;
	if (val_ascii < 0 || val_ascii > 127)
		more_error(5, line_number);
	printf("%c\n", val_ascii);
}
