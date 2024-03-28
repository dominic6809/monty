#include "monty.h"

/**
 * pstr_op - function to print the string starting at the top of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: The current line number in the Monty file
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)num_digit;

    while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
    {
        putchar(current->n);
        current = current->next;
    }
    putchar('\n');
}
