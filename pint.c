#include "monty.h"

/**
 * f_pint - a function to obtain top element
 * @head: top element in the stack
 * @counter: the number of lines used
 * Return: NULL, if sucessful
*/

void f_pint(stack_t **head, unsigned int num_digit)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", num_digit);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
