#include "monty.h"

/**
 * f_pall - program code to display the stack element
 * @head: top element in the stack
 *
 * @num_digit: number of line covered by the stack
 * Return: (NULL), successful, otherwise error
*/

void f_pall(stack_t **head, unsigned int num_digit)
{
	stack_t *u;
	(void)num_digit;

	u = *head;
	if (u == NULL)
		return;
	while (u)
	{
		printf("%d\n", u->n);
		u = u->next;
	}
}
