#include "monty.h"
/**
 * f_pop - print the top  var of the stack
 * @head: stack head
 * @counter: line_number
 * Return: null
*/
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *t;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	t = *head;
	*head = t->next;
	free(t);
}
