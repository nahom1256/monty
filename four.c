#include "monty.h"

/**
 * naopenfile - open
 * @file_name: the file namepath
 * Return: void
 */

void naopenfile(char *file_name)
{
	FILE *nd = fopen(file_name, "r");

	if (file_name == NULL || nd == NULL)
		naerr(2, file_name);

	naread(nd);
	fclose(nd);
}


/**
 * naread - read
 * @nd: pointer
 * Return: void
 */

void naread(FILE *nd)
{
	int naline_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (naline_number = 1; getline(&buffer, &len, nd) != -1; naline_number++)
	{
		format = naparseline(buffer, naline_number, format);
	}
	free(buffer);
}


/**
 * naparseline - Separates
 * which function to call
 * @buffer: line from the file
 * @naline_number: line number
 * @format:  storage format.
 * if
 * Return: Returns 0 if the opcode is stack.
 */

int naparseline(char *buffer, int naline_number, int format)
{
	char *naopcode, *navalue;
	const char *delim = "\n ";

	if (buffer == NULL)
		naerr(4);

	naopcode = strtok(buffer, delim);
	if (naopcode == NULL)
		return (format);
	navalue = strtok(NULL, delim);

	if (strcmp(naopcode, "stack") == 0)
		return (0);
	if (strcmp(naopcode, "queue") == 0)
		return (1);

	nafind(naopcode, navalue, naline_number, format);
	return (format);
}

/**
 * nafind - find
 * @naopcode: opcode
 * @navalue: argument
 * @format:  storage format.
 * @fu: line number
 * if 1 nodes
 * Return: void
 */
void nafind(char *naopcode, char *navalue, int fu, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", naadds},
		{"pall", naprintstack},
		{"pint", naprinttop},
		{"pop", napoptop},
		{"nop", nanop},
		{"swap", naswap},
		{"add", naadd},
		{"sub", nasub},
		{"div", nadiv},
		{"mul", namul},
		{"mod", namod},
		{"pchar", naprint},
		{"pstr", naprintstr},
		{"rotl", narotl},
		{"rotr", narotr},
		{NULL, NULL}
	};

	if (naopcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(naopcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, naopcode, navalue, fu, format);
			flag = 0;
		}
	}
	if (flag == 1)
		naerr(3, fu, naopcode);
}


/**
 * nacallfun - Calls.
 * @func: Pointer
 * @na: string.
 * @val: string.
 * @fu: line.
 * @format: Format.
 * if 1queue.
 */
void call_fun(naop_func func, char *na, char *val, int fu, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(na, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			naerr(5, fu);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				naerr(5, fu);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, fu);
		if (format == 1)
			naaddq(&node, fu);
	}
	else
		func(&nhead, fu);
}
