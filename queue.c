#include "monty.h"
/**
 * addqueue - a function to add node at the bottom of stack
 * @n: the new value to be added
 * @head: stack head
 * Return: none, if successful, otherwise error
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_n, *aux;

	aux = *head;
	new_n = malloc(sizeof(stack_t));
	if (new_n == NULL)
	{
		printf("Error\n");
	}
	new_n->n = n;
	new_n->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_n;
		new_n->prev = NULL;
	}
	else
	{
		aux->next = new_n;
		new_n->prev = aux;
	}
}
