#include "monty.h"


/**
 * create_node - create a node
 * @n: The value inside the node
 * Return: On succes a pointer to the node or NULL on fail
 */

stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Free nodes function
 */

void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * exec_fun - Call the appropriate function
 * @f: pointer to the function that we have to perform
 * @opcode: the string of operation code
 * @value: the value to apply on the function
 * @ln: the line that contains the instruction
 * @data_mode: the implementation mode to perform
 */

void exec_fun(void (*f)(), char *opcode, char *value, int ln, int data_mode)
{
	stack_t *node;
	int P = 1;
	int k;

	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			P = -1;
		}
		if (value == NULL)
			error(5, ln);

		for (k = 0; value[k] != '\0'; k++)
		{
			if (isdigit(value[k]) == 0)
				error(5, ln);
		}
		node = create_node(atoi(value) * P);
		if (data_mode == 0)
			f(&node, ln);
	}
	else
		f(&head, ln);
}
