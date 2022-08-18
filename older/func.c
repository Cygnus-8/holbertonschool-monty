#include "monty.h"


/**
 * *open_file - function to access & open file
 * @filename: file to start
 * Return: rd
 */

FILE *open_file(char *filename)
{
	int fd;
	FILE *rd;

	if (filename == NULL)
	{
		printf("USAGE: monty file\n");
		exit(8);
	}

	fd = access(filename, R_OK);

	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	rd = fopen(filename, O_RDONLY);

	if (rd == NULL)
		exit(8);

	return (rd);
}

/**
 * **read_file - function to getline & strtok
 * @rd: file descriptor
 * Return: 0
 */

char **read_file(FILE *rd)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t val;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	while ((val = getline(&buffer, &bufsize, rd)) != -1)
	{
		printf("%s\n", buffer);
	}

	/**val = fgets(buffer, bufsize, rd);
	buf = strtok(buffer, "\n");*/

	

	if (val == -1)
	{
		printf("L<line_number>: unknown instruction");
		free(buffer);
		fclose(rd);
		exit(8);
	}
	free(rd);
	return (0);
}
