#include "monty.h"

/**
 * f_pall - program code to display the stack element
 * @head: top element in the stack
 *
 * @counter: number of line covered by the stack
 * Return: (NULL), successful, otherwise error
*/

void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *u;
	(void)counter;

	u = *head;
	if (u == NULL)
		return;
	while (u)
	{
		printf("%d\n", u->n);
		u = u->next;
	}
}
