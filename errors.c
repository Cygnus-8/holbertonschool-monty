#include "monty.h"

/**
 * error - Prints errors messages according to
 * circumstances
 * @error_code: the error codes are:
 * (1) ~> The user does not give any file or more
 * than one argument to your program
 * (2) ~> If, for any reason, it’s not possible to open the file
 * (3) ~> If the file contains an invalid instruction
 * (4) ~> If you can’t malloc anymore
 * (5) ~> if <int> is not an integer or if there is no argument given to push
 */

void error(int error_code, ...)
{
	va_list args;
	char *op;
	int line_number;

	va_start(args, error_code);

	switch (error_code)
	{
		case 1:
			printf("USAGE: monty file\n");
			break;
		case 2:
			printf("Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			line_number = va_arg(args, int);
			op = va_arg(args, char *);
			printf("L%d: unknown instruction %s\n", line_number, op);
			break;
		case 4:
			printf("Error: malloc failed\n");
			break;
		case 5:
			printf("L%d: usage: push integer", va_arg(args, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
