#include "monty.h"

/**
 * main - Entry Point
 * @argc: Number of command line arguments.
 * @argv: An array containing the arguments.
 * Return: Always Zero.
 */

stack_t *head = NULL;

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		error(1);
	open_file(argv[1]);
	free_nodes();
	return (0);
}
