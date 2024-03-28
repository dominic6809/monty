#include "monty.h"

/**
 * rotr_op - function that rotates the stack to the bottom.
 * @stack: Double pointer to the beginning of the stack
 * @num_digit: The current line number in the Monty file
 */
void rotr(stack_t **head, unsigned int num_digit)
{
	stack_t *current;

	(void)num_digit;

	if (*head && (*head)->next)
	{
		current = *head;

		while (current->next)
			current = current->next;

		current->prev->next = NULL;
		current->prev = NULL;
		current->next = *head;
		(*head)->prev = current;
		*head = current;
	}
}
