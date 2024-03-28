#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

/* header preprocessors */
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>

/**
 * struct stack_s - representation of a doubly linked list for a stack
 * @n: integer
 * @prev: points previous element of stack
 * @next: points next element in the stack
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO program code
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
 * for stack, queues, LIFO, FIFO monty project
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
 * @content: line content
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

/* Stack functions */
void process_addqueue(stack_t **stack, int n);
void process_addnode(stack_t **stack, int n);
void process_free_stack(stack_t *stack);
void process_f_stack(stack_t **stack, unsigned int line_num);
void execute(char *line_content, stack_t **stack, unsigned int line_counter, FILE *monty_file);

/* Error handlers */
void process_usage_err(void);
void process_f_open_err(char *filename);
void process_invalid_op_err(char *opcode, unsigned int line_num);
void process_malloc_err(void);
void process_push_err(unsigned int line_num);
void process_pint_err(unsigned int line_num);
void process_pop_err(unsigned int line_num);
void process_swap_err(unsigned int line_num);
void process_add_err(unsigned int line_num);
void process_sub_err(unsigned int line_num);

/* opcode functions */
void process_push(stack_t **stack, unsigned int line_num);
void process_pall(stack_t **stack, unsigned int line_num);
void process_pint(stack_t **stack, unsigned int line_num);
void process_pop(stack_t **stack, unsigned int line_num);
void process_swap(stack_t **stack, unsigned int line_num);
void process_add(stack_t **stack, unsigned int line_num);
void process_nop(stack_t **stack, unsigned int line_num);
void process_sub(stack_t **stack, unsigned int line_num);
void process_div(stack_t **stack, unsigned int line_num);
void process_mul(stack_t **stack, unsigned int line_num);
void process_mod(stack_t **stack, unsigned int line_num);
void process_pchar(stack_t **stack, unsigned int line_num);
void process_rotr(stack_t **stack, unsigned int line_num);
void process_queue(stack_t **stack, unsigned int line_num);
void process_stack(stack_t **stack, unsigned int line_num);

#endif /* MONTY_H */
