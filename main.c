#include "monty.h"
#define _GNU_SOURCE

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success, otherwise error
 */
int main(int argc, char *argv[])
{
	char *line_content;
	FILE *monty_file;
	size_t buffer_size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_counter = 0;

	if (argc != 2)
	process_usage_err();

	monty_file = fopen(argv[1], "r");
	bus.file = monty_file;
	if (!monty_file)
	process_f_open_err(argv[1]);

	while (read_line > 0)
	{
	line_content = NULL;
	read_line = getline(&line_content, &buffer_size, monty_file);
	bus.content = line_content;
	line_counter++;
	if (read_line > 0)
	{
	execute(line_content, &stack, line_counter, monty_file);
	}
	free(line_content);
	}
	process_free_stack(stack);
	fclose(monty_file);
	return (0);
}
