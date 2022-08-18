#include "monty.h"

/**
 * main - function to run Monty
 * @argc: argc
 * @argv: argv
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *buff;
	FILE *fd;

	if (argc == 0)
		return (0);

	buff = malloc(sizeof(char) * 1024);

	fd = open_file(argv[1]);
	read_file(fd);

	printf("%s\n", buff);

	return (0);
}
