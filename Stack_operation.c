#include "monty.h"

/**
 * add_to_stack - add a node to the stack
 * @node_to_add: the new node to add
 * @line_number: line that contains the instruction
 */

void add_to_stack(stack_t **node_to_add, __attribute__((unused)) unsigned int line_number)
{
    stack_t *tmp;

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
    while (stack != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}