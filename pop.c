#include "monty.h"

/**
 * f_pop - function to display the top element of the stack
 * @head: head stack
 * @counter: number of lines
 * Return: sucess NULL, -1 error
*/

void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *u;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	u = *head;
	*head = u->next;
	free(u);
}
