#include "monty.h"

/**
 * narotl - Rotates
 * @stack: Pointer
 * @fu: Interger
 */
void narotl(stack_t **stack, __attribute__((unused))unsigned int fu)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * narotr - Rotates
 * @stack: Pointer
 * @fu: Interger
 */
void narotr(stack_t **stack, __attribute__((unused))unsigned int fu)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
