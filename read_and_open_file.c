#include "monty.h"

/**
 * open_file - open the .m type file
 * @file_name: the name of the file
 * Return: fd the file descriptor
 */

void open_file(char *file_name)
{
	FILE *fd;

	if (file_name == NULL)
		error(2, file_name);

	fd = fopen(file_name, "r");

	if (fd == NULL)
		error(2, file_name);
	read_line(fd);
	fclose(fd);
}

/**
 * read_line - Read the file opened previously
 * @fd: File descriptor stream on the file opened
 */

void read_line(FILE *fd)
{
	char *lineptr;
	size_t n;
	int data_mode = 0, line_number;

	lineptr = NULL;
	n = 0;

	for (line_number = 1; getline(&lineptr, &n, fd) != -1; line_number++)
	{
		data_mode = line_interpreter(lineptr, line_number, data_mode);
	}

	free(lineptr);
}

/**
 * line_interpreter - interpret line by line
 * @lineptr: string that contains the line to interpret
 * @line_number: number of the line in the text
 * @data_mode: 0 if it's stack implementation or
 * 1 if it's queue implementation
 * Return: the data mode implemented
 */

int line_interpreter(char *lineptr, int line_number, int data_mode)
{
	const char *delim;
	char *opcode;
	char *value;

	if (lineptr == NULL)
		error(4);

	delim = "\n ";
	opcode = strtok(lineptr, delim);
	if (opcode == NULL)
		return (data_mode);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "queue") == 0)
		return (1);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	search_func(opcode, value, line_number, data_mode);
	return (data_mode);
}

/**
 * search_func - search the function corresponding to the opcode
 * @opcode: the string operation code to perform
 * @value: the string of value to apply to opcode
 * @line_number: line that contains the instruction
 * @data_mode: the implementation mode to perform
 */

void search_func(char *opcode, char *value, int line_number, int data_mode)
{
	int k;
	int debug;
	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", pint_func},
		{"pop", pop_func},
		{NULL, NULL}};

	for (debug = 1, k = 0; func_list[k].opcode != NULL; k++)
	{
		if (strcmp(opcode, func_list[k].opcode) == 0)
		{
			exec_fun(func_list[k].f, opcode, value, line_number, data_mode);
			debug = 0;
		}
	}
	if (debug == 1)
		error(3, line_number, opcode);
}
