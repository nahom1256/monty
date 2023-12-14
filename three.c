#include "monty.h"

/**
 * naerr - Printserror
 * namoreerr - error
 * nastringerr - string error
 * @errortype: The error codes are
 * (0) => The user does not give any file or more than one file to the program.
 * (1) => The file provided is not a file that can be opened or read.
 * (2) => The file provided contains an invalid instruction.
 * (3) => When the program is unable to malloc more memory.
 * (4) => When the parameter passed to the instruction "push" is not an int.
 * (5) => When the stack it empty for pint.
 * (6) => When the stack it empty for pop.
 * (7) => When stack is too short for operation.
 */
void naerr(int errortype, ...)
{
	va_list ag;
	char *na;
	int so;

	va_start(ag, errortype);
	switch (errortype)
	{
		case 0:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 1:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 4:
			so = va_arg(ag, int);
			na = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", so, na);
			break;
		case 5:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 6:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
void namoreerr(int errortype, ...)
{
	va_list ag;
	char *na;
	int so;

	va_start(ag, errortype);
	switch (errortype)
	{
		case 7:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 8:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 9:
			so = va_arg(ag, unsigned int);
			na = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", so, na);
			break;
		case 10:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
void nastringerr(int errortype, ...)
{
	va_list ag;
	int so;

	va_start(ag, errortype);
	so = va_arg(ag, int);
	switch (errortype)
	{
		case 11:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", so);
			break;
		case 12:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", so);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
