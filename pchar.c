#include "monty.h"

/**
 * pchar_op - function that prints the char at the top of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: The current line number in the Monty file
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
    if (!stack || !(*stack))
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", num_digit);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%d: cannot pchar, value out of range\n", num_digit);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (*stack)->n);
}
