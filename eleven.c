#include "monty.h"

/**
 * namul - Adds
 * @nastack: Pointer
 * @line_number: Interger representing the line number of of the opcode.
 */
void namul(stack_t **nastack, unsigned int line_number)
{
	int sum;

	if (nastack == NULL || *nastack == NULL || (*nastack)->next == NULL)
		namoreerr(8, line_number, "mul");

	(*nastack) = (*nastack)->next;
	sum = (*nastack)->n * (*nastack)->prev->n;
	(*nastack)->n = sum;
	free((*nastack)->prev);
	(*nastack)->prev = NULL;
}


/**
 * namod - Adds
 * @stack: Pointer
 * @line_number: Interger
 */
void namod(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		namoreerr(8, line_number, "mod");


	if ((*stack)->n == 0)
		namoreerr(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
