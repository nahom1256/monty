#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *nhead;
typedef void (*naop_func)(stack_t **, unsigned int);


void naopenfile(char *file_name);
int naparseline(char *buffer, int line_number, int format);
void naread(FILE *);
int nachars(FILE *);
void nafind(char *, char *, int, int);

void naprint(stack_t **, unsigned int);
void naprintstr(stack_t **, unsigned int);
void narotl(stack_t **, unsigned int);

void namoreerr(int error_code, ...);
void naerr(int error_code, ...);
void nastringerr(int error_code, ...);
void narotr(stack_t **, unsigned int);

stack_t *create_node(int n);
void free_nodes(void);
void naprintstack(stack_t **, unsigned int);
void naaddq(stack_t **, unsigned int);
void naadds(stack_t **, unsigned int);


void call_fun(naop_func, char *, char *, int, int);
void naadd(stack_t **, unsigned int);
void nasub(stack_t **, unsigned int);
void nadiv(stack_t **, unsigned int);
void namul(stack_t **, unsigned int);
void namod(stack_t **, unsigned int);

void naprinttop(stack_t **, unsigned int);
void napoptop(stack_t **, unsigned int);
void nanop(stack_t **, unsigned int);
void naswap(stack_t **, unsigned int);

#endif
