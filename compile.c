#include "monty.h"

/**
 * execute - interprets Monty bytecode instructions from a file
 * @line_content: line content from the Monty file
 * @stack: Ptr to the stack of integers
 * @line_counter: Current line number in the Monty file
 * @monty_file: Pointer to the Monty file being processed
 * Return: 0 on successful execution, 1 on failure
 */
void execute(char *line_content, stack_t **stack,
             unsigned int line_counter, FILE *monty_file)
{
    instruction_t opcode_func[] = {
        {"push", process_push}, {"pall", process_pall},
        {"pint", process_pint}, {"pop", process_pop},
        {"swap", process_swap}, {"add", process_add},
        {"nop", process_nop}, {"sub", process_sub},
        {"div", process_div}, {"mul", process_mul},
        {"mod", process_mod}, {"pchar", process_pchar},
        {"rotr", process_rotr}, {"queue", process_queue},
        {"stack", process_stack}, {NULL, NULL}
    };

    char *op_code = strtok(line_content, " \n\t");

    if (op_code && op_code[0] == '#')
        return;

    bus.arg = strtok(NULL, " \n\t");

    for (unsigned int pos = 0; opcode_func[pos].opcode; pos++)
    {
        if (strcmp(op_code, opcode_func[pos].opcode) == 0)
        {
            opcode_func[pos].f(stack, line_counter);
            return;
        }
    }

    if (op_code)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, op_code);
        fclose(monty_file);
        free(line_content);
        process_free_stack(*stack);
        exit(EXIT_FAILURE);
    }
}
