#include "monty.h"

/**
 * f_div - function that divides the top two elements of the stack.
 * @head: head of the stack
 *
 * @num_digit: number of lines
 *
 * Return: NULL, upon successful execution
*/

void f_div(stack_t **head, unsigned int num_digit)
{
	stack_t *u;
	int val = 0, aux;

	u = *head;
	while (t)
	{
		u = u->next;
		val++;
	}
	if (val < 2)
	{
		fprintf(stderr, "L%d: cannot div, stack too short\n", num_digit);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	u = *head;
	if (u->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num_digit);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = u->next->n / u->n;
	u->next->n = aux;
	*head = u->next;
	free(u);
}
