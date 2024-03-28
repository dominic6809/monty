#include "monty.h"

/**
 * f_mul - function that multiplies the second top element
 * of the stack with the top element of the stack
 * @head: head stack
 * @counter: number of lines inputed
 *
 * Return: void
*/

void f_mul(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	u = *head;
	aux = u->next->n * u->n;
	u->next->n = aux;
	*head = u->next;
	free(u);
}
