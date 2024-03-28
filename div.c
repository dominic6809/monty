#include "monty.h"

/**
 * f_div - function that divides the top two elements of the stack.
 * @head: head of the stack
 *
 * @counter: number of lines
 *
 * Return: NULL, upon successful execution
*/

void f_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: cannot div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	u = *head;
	if (u->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
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
