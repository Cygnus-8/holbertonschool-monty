#include "monty.h"

/**
 * add_to_stack - add a node to the stack
 * @node_to_add: the new node to add
 * @line_number: line that contains the instruction
 */

void add_to_stack(stack_t **node_to_add, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (node_to_add == NULL || *node_to_add == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node_to_add;
		return;
	}
	tmp = head;
	head = *node_to_add;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * print_stack - Print the stack
 * @stack: the node that represent the stack
 * @line_number: line that contains the instruction
 */

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * swap_nodes - swaps the top two elements of the stack
 * @stack: Pointer of pointer that points to the top of the stack
 * @line_number: Line that contains the instruction
 */

void swap_nodes(stack_t **stack, unsigned int line_number)
{

	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(1, line_number);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - Adds the top of two elements of the stack
 * @stack: Pointer of pointer that points to the top of the stack
 * @line_number: Line that contains the instruction
 */

void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(2, line_number);

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop - Perform nothing
 * @stack: Pointer of pointer that points to the top of the stack
 * @line_number: Line that contains the instruction
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
