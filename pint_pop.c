#include "monty.h"

/**
 * pint_func -  prints the value at the top of the stack
 * @last: last node
 * @line_number: ...
 */
void pint_func(stack_t **last, unsigned int line_number)
{
	stack_t *tmp = *last;
	(void)line_number;

	if (tmp != NULL)
		printf("%d\n", tmp->n);
	else
		error(6, line_number);
}

/**
 * pop_func - removes the top element of the stack
 * @last: last node
 * @line_number: ...
 */
void pop_func(stack_t **last, unsigned int line_number)
{
	stack_t *tmp = *last;

	if (*last != NULL)
	{
		tmp = tmp->next;
		free(*last);
		*last = tmp;
	}
	else
		error(7, line_number);
}

/**
 * sub_func - subtracts the top element of the stack
 * @stack: last node
 * @line_number: ...
 */
void sub_func(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_more_error(1, line_number);

	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_func - divides the second top element of the stack
 * @stack: last node
 * @line_number: ...
 */
void div_func(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_more_error(2, line_number);

	if ((*stack)->n == 0)
		more_more_error(4, line_number);

	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_func - multiplies the second top element of the stack
 * @stack: last node
 * @line_number: ...
 */
void mul_func(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_more_error(3, line_number);

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
