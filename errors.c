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
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
		break;
	case 3:
		line_number = va_arg(args, int);
		op = va_arg(args, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5:
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
		break;
	case 6:
		line_number = va_arg(args, int);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		break;
	case 7:
		line_number = va_arg(args, int);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		break;
	default:
		break;
	}
	va_end(args);
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_error - Print an error message according
 * to circumstance
 * @error_code: the error code are:
 * (1) ~> If the stack contains less than two elements
 * (2) ~> If the stack contains less than two elements
 */

void more_error(int error_code, ...)
{
	va_list args;

	va_start(args, error_code);

	switch (error_code)
	{
	case 1:
		fprintf(stderr, "L%d: can't swap, stack too short\n", va_arg(args, int));
		break;
	case 2:
		fprintf(stderr, "L%d: can't add, stack too short\n", va_arg(args, int));
		break;
	case 3:
		fprintf(stderr, "L%d: can't mod, stack too short\n", va_arg(args, int));
		break;
	case 4:
		fprintf(stderr, "L%d: division by zero\n", va_arg(args, int));
		break;
	case 5:
		fprintf(stderr, "L%d: can't pchar, value out of range\n", va_arg(args, int));
		break;
	case 6:
		fprintf(stderr, "L%d: can't pchar, stack empty\n", va_arg(args, int));
		break;
	default:
		break;
	}
	va_end(args);
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_more_error - Print an error message according
 * to circumstance
 * @error_code: the error code are:
 * (1) ~> If the stack contains less than two elements
 * (2) ~> If the stack contains less than two elements
 */

void more_more_error(int error_code, ...)
{
	va_list args;

	va_start(args, error_code);

	switch (error_code)
	{
	case 1:
		fprintf(stderr, "L%d: can't sub, stack too short\n", va_arg(args, int));
		break;
	case 2:
		fprintf(stderr, "L%d: can't div, stack too short\n", va_arg(args, int));
		break;
	case 3:
		fprintf(stderr, "L%d: can't mul, stack too short\n", va_arg(args, int));
		break;
	case 4:
		fprintf(stderr, "L%d: division by zero\n", va_arg(args, int));
		break;
	default:
		break;
	}
	va_end(args);
	free_nodes();
	exit(EXIT_FAILURE);
}
