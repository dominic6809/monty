#include "monty.h"
/**
  *f_sub- program to perform subtraction operation
  *@head: the top stack
  *@num_digit: the number of lines present
  *Return: none success, otherwise error
 */
void f_sub(stack_t **head, unsigned int num_digit)
{
	stack_t *aux;
	int z, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: cannot subtract, stack too short\n", num_digit);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	z = aux->next->n - aux->n;
	aux->next->n = z;
	*head = aux->next;
	free(aux);
}
