#include "monty.h"

/**
 * mod_op - Computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @head: head of the stack
 *@mod: modulus of two integers
 * @stack: Double pointer to the beginning of the stack
 * @num_digit: The current line number in the Monty file
 */
void mod(stack_t **head, unsigned int num_digit)
{
	stack_t *top, *second_top;

	if (!stack || !(*head) || !((*head)->next))
	{
		fprintf(stderr, "L%d: cannot mod, stack too short\n", num_digit);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	top = *head;
	second_top = top->next;

	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num_digit);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	second_top->n %= top->n;
	*head = second_top;
	(*head)->prev = NULL;
	free(top);
}
