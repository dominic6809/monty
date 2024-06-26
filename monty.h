#ifndef MONTY_H
#define MONTY_H

/* Macro constants */
#define _GNU_SOURCE
#define MAX_STACK_SIZE 100

/* header directives */
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <fcntl.h>

/* structure */
/**
 * struct stack_s - DLL representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO monty project
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: contents of line
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */

typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;

extern bus_t bus;
extern char **environ;

/* prototypes */
int execute(char *line_content, stack_t **stack, unsigned int num_digit, FILE *monty_file);
void f_push(stack_t **head, unsigned int num_digit);
void f_pall(stack_t **head, unsigned int num_digit);
void free_stack(stack_t *head);
void f_pint(stack_t **head, unsigned int num_digit);
void f_pop(stack_t **head, unsigned int num_digit);
void addnode(stack_t **head, int i);
void addqueue(stack_t **head, int i);
void f_add(stack_t **head, unsigned int num_digit);
void f_queue(stack_t **head, unsigned int num_digit);
void f_nop(stack_t **head, unsigned int num_digit);
void f_swap(stack_t **head, unsigned int num_digit);
void f_stack(stack_t **head, unsigned int num_digit);
void f_sub(stack_t **head, unsigned int num_digit);
void f_div(stack_t **head, unsigned int num_digit);
void f_mul(stack_t **head, unsigned int num_digit);
void mod(stack_t **head, unsigned int num_digit);
void pchar(stack_t **head, unsigned int num_digit);
void pstr(stack_t **head, unsigned int num_digit);
void rotl(stack_t **head, unsigned int num_digit);
void rotr(stack_t **head, unsigned int num_digit);

#endif /* MONTY_H */
