#include "monty.h"
/**
 * f_push - function to add node to the stack
 * @head: overhead stak
 * @counter: number of lines
 * Return: NULL, sucess, error elsewhere
*/
void f_push(stack_t **head, unsigned int counter)
{
	int r, t = 0, index = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			t++;
		for (; bus.arg[t] != '\0'; t++)
		{
			if (bus.arg[t] > 57 || bus.arg[t] < 48)
				index = 1; }
		if (index == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	r = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, r);
	else
		addqueue(head, r);
}
