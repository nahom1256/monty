#include "monty.h"

/**
 * naadd - Adds
 * @nastack: Pointer
 * @line_number: Interger representing the line number of of the opcode.
 */
void naadd(stack_t **nastack, unsigned int line_number)
{
	int sum;

	if (nastack == NULL || *nastack == NULL || (*nastack)->next == NULL)
		namoreerr(8, line_number, "add");

	(*nastack) = (*nastack)->next;
	sum = (*nastack)->n + (*nastack)->prev->n;
	(*nastack)->n = sum;
	free((*nastack)->prev);
	(*nastack)->prev = NULL;
}


/**
 * nasub - Adds the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nasub(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		namoreerr(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
