#include "monty.h"

/**
* free_stack - function that frees a Doubly Linked List
* @head: head stack
*
* Return: Null, sucessful
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	for (; head; head = aux)
	{
	    aux = head->next;
	    free(head);
	}
}
