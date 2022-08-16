#include "monty.h"

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    char buffer[500];

    if (argv[1] == NULL)
    {
        printf("USAGE: monty file\n");
        exit(1);
    }

    if (fd < 0)
    {
        printf("Error: Can't open file <file>\n");
        exit(1);
    }

    if (read(fd, buffer, sizeof(buffer)) == -1)
    {
        printf("L<line_number>: unknown instruction <opcode>\n");
        exit(1);
    }
    else
        printf("%s\n", buffer);

        
}