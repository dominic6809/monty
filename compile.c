#include "monty.h"

/**
 * execute - Executes Monty bytecode instructions from a file
 * @line_content: Line content from the Monty file
 * @stack: Pointer to the stack of integers
 * @line_counter: Current line number in the Monty file
 * @monty_file: Pointer to the Monty file being processed
 *
 * Return: void
 */
void execute(char *line_content, stack_t **stack,
		unsigned int line_counter, FILE *monty_file)
{
	static instruction_t opcode_func[] = {
		{"push", process_push}, {"pall", process_pall},
		{"pint", process_pint}, {"pop", process_pop},
		{"swap", process_swap}, {"add", process_add},
		{"nop", process_nop},   {"sub", process_sub},
		{"div", process_div},   {"mul", process_mul},
		{"mod", process_mod},   {"pchar", process_pchar},
		{"rotr", process_rotr}, {"queue", process_queue},
		{"stack", process_stack}, {NULL, NULL}
	};

	unsigned int i = 0;
	char *op_code = strtok(line_content, " \n\t");

	if (!op_code || op_code[0] == '#')
		return;

	bus.arg = strtok(NULL, " \n\t");

	while (opcode_func[i].opcode)
	{
		if (strcmp(op_code, opcode_func[i].opcode) == 0)
		{
			opcode_func[i].f(stack, line_counter);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",
			line_counter, op_code);
	fclose(monty_file);
	free(line_content);
	process_free_stack(*stack);
	exit(EXIT_FAILURE);
}
