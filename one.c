#include "monty.h"
stack_t *nhead = NULL;

/**
 * main - entry
 * @naargc: argument
 * @naargv: arguments
 * Return: always 0
 */

int main(int naargc, char *naargv[])
{
	if (naargc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	naopenfile(naargv[1]);
	free_nodes();
	return (0);
}

/**
 * newnode - Creates a node
 * @m: Number
 * Return: Upon sucess
 */
stack_t *create_node(int m)
{
	stack_t *nanode;

	nanode = malloc(sizeof(stack_t));
	if (nanode == NULL)
		naerr(4);
	nanode->next = NULL;
	nanode->prev = NULL;
	nanode->n = m;
	return (nanode);
}

/**
 * free_nodes - Frees node
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (nhead == NULL)
		return;

	while (nhead != NULL)
	{
		tmp = nhead;
		nhead = nhead->next;
		free(tmp);
	}
}
