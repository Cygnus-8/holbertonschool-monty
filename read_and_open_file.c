#include "monty.h"

/**
 * open_file - open the .m type file
 * @file_name: the name of the file
 * Return: fd the file descriptor
 */

FILE *open_file(char *file_name)
{
    int check_file;
    FILE *fd;

    if (file_name == NULL)
        exit(EXIT_FAILURE);
    check_file = access(file_name, R_OK);
    if (check_file == -1)
        exit(EXIT_FAILURE);

    fd = fopen(file_name, "r");

    if (fd == NULL)
        exit(EXIT_FAILURE);

    return (fd);
}

/**
 * read_file - Read the file opened previously
 * @fd: File descriptor stream on the file opened
 */

char **read_line(FILE *fd)
{
    char **lineptr;
    size_t *n;
    ssize_t P;

    lineptr = NULL;
    n = 0;
    if (fd == NULL)
        exit(EXIT_FAILURE);
    
    P = getline(lineptr, n, fd);

    if (P == -1)
    {
        free(lineptr);
        fclose(fd);
    }

    
}