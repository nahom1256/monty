#include "monty.h"


/**
 * naadds - Adds
 * @new_node: pointer
 * @fu: Interger
 */
void naadds(stack_t **new_node, __attribute__((unused))unsigned int fu)
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
	nhead = *new_node;
	nhead->next = tmp;
	tmp->prev = nhead;
}
