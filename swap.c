#include "monty.h"

/**
 * f_swap - function that adds the top two elements of the stack.
 * @head: stack head to point to the next
 * @num_digit: number of lines
 *
 * Return: NULL success
*/

void f_swap(stack_t **head, unsigned int num_digit)
{
	stack_t *u;
	int val = 0, aux;

	u = *head;
	while (u)
	{
		u = u->next;
		val++;
	}
	if (val < 2)
	{
		fprintf(stderr, "L%d: cannot swap, stack too short\n", num_digit);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	u = *head;
	aux = u->n;
	u->n = u->next->n;
	u->next->n = aux;
}
