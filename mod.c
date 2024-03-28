#include "monty.h"

/**
 * mod_op - Computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: The current line number in the Monty file
 */
void mod_op(stack_t **stack, unsigned int num_digit)
{
    stack_t *top, *second_top;

    if (!stack || !(*stack) || !((*stack)->next))
    {
        fprintf(stderr, "L%d: cannot mod, stack too short\n", num_digit);
        exit(EXIT_FAILURE);
    }

    top = *stack;
    second_top = top->next;

    if (top->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", num_digit);
        exit(EXIT_FAILURE);
    }

    second_top->n %= top->n;
    *stack = second_top;
    (*stack)->prev = NULL;
    free(top);
}
