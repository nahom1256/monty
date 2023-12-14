#include "monty.h"

/**
 * nadiv - div
 * @stack: Pointer
 * @line_number: Interger representing the line number of of the opcode.
 */
void nadiv(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		namoreerr(8, line_number, "div");

	if ((*stack)->n == 0)
		namoreerr(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
