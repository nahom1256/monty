#include "monty.h"

/**
 * naaddq - Adds to the queue.
 * @new_node: Pointer
 * @l: line number
 */
void naaddq(stack_t **new_node, __attribute__((unused))unsigned int l)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (nhead == NULL)
	{
		nhead = *new_node;
		return;
	}
	tmp = nhead;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
