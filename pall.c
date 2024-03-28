#include "monty.h"
/**
 * f_pall - prints stack
 * @head: stack head
 * @counter: line_number
 * Return: null
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *t;
	(void)counter;

	t = *head;
	if (t == NULL)
		return;
	while (t)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}
