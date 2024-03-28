#include "monty.h"

/**
 * process_usage_err - prints error message for incorrect command line usage
 */
 
void process_usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * process_f_open_err - prints error message for file opening failure
 * @filename: Name of the file that failed to open
 */
 
void process_f_open_err(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * process_invalid_op_err - displays an error message for unknown opcode
 * @opcode: The unknown opcode encountered
 * @line_num: Line number where the error occurred
 */
 
void process_invalid_op_err(char *opcode, unsigned int line_num)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
	exit(EXIT_FAILURE);
}

/**
 * process_malloc_err - Prints an error message for malloc failure
 */
void process_malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * process_push_err - displays an error message for invalid push arguments
 * @line_num: Line number where the error occurred
 */
void process_push_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_num);
	exit(EXIT_FAILURE);
}
