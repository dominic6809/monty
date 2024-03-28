#include "monty.h"

/**
 * rotl_op - rotates the stack to the top.
 * @stack: Double pointer to the beginning of the stack
 * @num_digit: The current line number in the Monty file
 */
void rotl(stack_t **head, unsigned int num_digit)
{
    stack_t *current, *new_top;

    (void)num_digit;

    if (*head && (*head)->next)
    {
        current = *head;
        new_top = current->next;

        while (current->next)
            current = current->next;

        current->next = *head;
        *head = new_top;
        (*head)->prev = NULL;
        current->next->prev = current;
    }
}
