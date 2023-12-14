#include "monty.h"

/**
 * napoptop - Adds
 * @stack: P
 * @line_number: I
 */
void napoptop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		namoreerr(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * naprintop - P
 * @stack: Pointer to a pointer
 * @line_number: Int
 */
void naprinttop(stack_t **nastack, unsigned int line_number)
{
	if (nastack == NULL || *nastack == NULL)
		namoreerr(6, line_number);
	printf("%d\n", (*nastack)->n);
}
