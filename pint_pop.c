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
