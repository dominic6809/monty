#include "monty.h"

/**
 * process_pint_err - Displays error message
 * for attempting to print from an empty stack
 * @num_digit: Line number where the error occurred
 */
void process_pint_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * process_pop_err - Outputs error message
 * for attempting to pop from an empty stack
 * @line_num: Line number where the error occurred
 */
void process_pop_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * process_swap_err - Shows error message
 * for attempting to swap with an insufficient stack
 * @line_num: Line number where the error occurred
 */
void process_swap_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * process_add_err - Gives error message for
 * attempting to add with insufficient elements
 * @line_num: Line number where the error occurred
 */
void process_add_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * process_sub_err - Prints error message for
 * attempting to subtract with insufficient elements
 * @line_num: Line number where the error occurred
 */
void process_sub_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}
