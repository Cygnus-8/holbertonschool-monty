#include "monty.h"

void op_check(char *line)
{
    char *buffer;
    int i = 0;
    int x;
    char *head = NULL;

    instruction_t op[] = {
        {"push", push},
        {NULL, NULL}
    };
    buffer = strtok(line, " ");
    
    while(buffer[i])
    {
        if (strcmp(buffer[0], opcode[i].op))
        {
            {
                if(i == 0)
                push(buffer[1], head);
            }
            //x = (opcode[i].f);
        }
        i++;
    }
    free(buffer);
}

stack_t push(char *arg, char *head)
{
    stack_t *node;

    node = malloc(sizeof(stack_t));

    if (node == 0)
        {
            free(node);
            return(NULL);
        }

    if (head == NULL)
    {
        node->n = arg;

        node->next = NULL;
        node->prev = NULL;

        head = node;
    }
    else
        
}

