#include "monty.h"

/**
 * rotr_op - function that rotates the stack to the bottom.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: The current line number in the Monty file
 */
void rotr_op(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    (void)num_digit;

    if (*stack && (*stack)->next)
    {
        current = *stack;

        while (current->next)
            current = current->next;

        current->prev->next = NULL;
        current->prev = NULL;
        current->next = *stack;
        (*stack)->prev = current;
        *stack = current;
    }
}
