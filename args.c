#include "monty.h"

/**
 * f_add - function that adds the top two elements of the stack.
 * @head: head stack
 * @counter: number of lines
 *
 * Return: NULL, successful
*/

void f_add(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	u = *head;
	aux = u->n + u->next->n;
	u->next->n = aux;
	*head = u->next;
	free(u);
}

/**
 * f_queue - function to show the tail of stack
 * @head: head stack
 *
 * @counter: number of lines
 * Return: NuLl, sucess -1 error
*/

void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}
