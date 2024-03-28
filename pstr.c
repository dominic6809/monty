#include "monty.h"

/**
 * pstr_op - function to print the string starting at the top of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @num_digit: The current line number in the Monty file
 */
void pstr(stack_t **head, unsigned int num_digit)
{
    stack_t *current = *head;

    (void)num_digit;

    while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
    {
        putchar(current->n);
        current = current->next;
    }
    putchar('\n');
}
