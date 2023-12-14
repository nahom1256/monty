#include "monty.h"

/**
 * naprint - Prints
 * @nastack: Pointer
 * @line_number: Interger
 */
void naprint(stack_t **nastack, unsigned int line_number)
{
	int ascii;

	if (nastack == NULL || *nastack == NULL)
		nastringerr(11, line_number);

	ascii = (*nastack)->n;
	if (ascii < 0 || ascii > 127)
		nastringerr(10, line_number);
	printf("%c\n", ascii);
}

/**
 * naprintstr - Prints
 * @stack: Pointer
 * @fu: Interger
 */
void naprintstr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}
