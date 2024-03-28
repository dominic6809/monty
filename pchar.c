#include "monty.h"

/**
 * pchar_op - function that prints the char at the top of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @num_digit: The current line number in the Monty file
 */
void pchar(stack_t **head, unsigned int num_digit)
{
    if (!stack || !(*head))
    {
        fprintf(stderr, "L%d: cannot pchar, stack empty\n", num_digit);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
        exit(EXIT_FAILURE);
    }

    if ((*head)->n < 0 || (*head)->n > 127)
    {
        fprintf(stderr, "L%d: cannot pchar, value out of range\n", num_digit);
        fclose(bus.file);
	free(bus.content);
	free_stack(*head);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (*head)->n);
}
