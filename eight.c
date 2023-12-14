#include "monty.h"

/**
 * nanop - Does
 * @nastack: Pointer
 * @line_number: Interger
 */
void nanop(stack_t **nastack, unsigned int line_number)
{
	(void)nastack;
	(void)line_number;
}


/**
 * naswap - Swaps
 * @nastack: Pointer
 * @line_number: Interger representing the line number of of the opcode.
 */
void naswap(stack_t **nastack, unsigned int line_number)
{
	stack_t *tmp;

	if (nastack == NULL || *nastack == NULL || (*nastack)->next == NULL)
		namoreerr(8, line_number, "swap");
	tmp = (*nastack)->next;
	(*nastack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *nastack;
	tmp->next = *nastack;
	(*nastack)->prev = tmp;
	tmp->prev = NULL;
	*nastack = tmp;
}
