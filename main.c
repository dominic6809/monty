#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - entry-point
* @argc: argument count
* @argv: argument vector
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *line_content;
	FILE *monty_file;
	size_t line_size = 0;
	ssize_t read_result = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	bus.file = monty_file;
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_result > 0)
	{
		line_content = NULL;
		read_result = getline(&line_content, &line_size, monty_file);
		bus.content = line_content;
		counter++;
		if (read_result > 0)
		{
			execute(line_content, &stack, counter, monty_file);
		}
		free(line_content);
	}
	free_stack(stack);
	fclose(monty_file);
return (0);
}
