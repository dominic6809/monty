#include "monty.h"

/**
 * f_pop - function to display the top element of the stack
 * @head: head stack
 * @num_digit: number of lines
 * Return: sucess NULL, -1 error
*/

void f_pop(stack_t **head, unsigned int num_digit)
{
	stack_t *u;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num_digit);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	u = *head;
	*head = u->next;
	free(u);
}
