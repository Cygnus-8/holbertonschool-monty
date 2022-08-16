#include "monty.h"

void open_file(char *filename)
{
    if (filename == NULL)
    {
        printf("USAGE: monty file");
        exit(8);
    }

    int fd = access(filename, R_OK);

    if (fd == -1)
    {
        printf("Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int rd = open(filename, O_RDONLY);

        if (rd ==c )

}
