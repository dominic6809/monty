#include "monty.h"
/**
 * rotl_op - rotates the stack to the top.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: The current line number in the Monty file
 */

void rotl_op(stack_t **stack, unsigned int line_number)
{
    stack_t *current, *new_top;

    (void)num_digit;

    if (*stack && (*stack)->next)
    {
        current = *stack;
        new_top = current->next;

        while (current->next)
            current = current->next;

        current->next = *stack;
        *stack = new_top;
        (*stack)->prev = NULL;
        current->next->prev = current;
    }
}
