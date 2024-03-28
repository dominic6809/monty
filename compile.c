#include "monty.h"

/**
* execute - function to executes the main function
* @stack: head of Doubly linked list stack
* @counter: line_counter
* @monty_file: a poiner to monty file
* @line_content: contents of the line
* Return: 1 sucess
*/

int execute(char *line_content, stack_t **stack,
		unsigned int counter, FILE *monty_file)
{
	instruction_t opst[] = {
				{"push", f_push},
				{"pall", f_pall},
				{"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"queue", f_queue},
				{"stack", f_stack},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{NULL, NULL}
				};
	unsigned int z = 0;
	char *opcode;

	opcode = strtok(line_content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[z].opcode && opcode)
	{
		if (strcmp(opcode, opst[z].opcode) == 0)
		{	opst[z].f(stack, counter);
			return (0);
		}
		z++;
	}
	if (opcode && opst[z].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
		fclose(monty_file);
		free(line_content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
