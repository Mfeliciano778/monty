#include "lists.h"
/**
 * is_comm - get operator function
 * @op_code: Name of commmand we're looking for
 *
 * Return: A pointer to the function if a match is found, or NULL if no match.
 */
void (*is_comm(char *op_code))(stack_t **stack, unsigned int line_number)
{
    instruction_t cmds[] = {
		{"push", push},
		{"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", NULL},
        {"NULL", NULL}
    };
    int index;
    unsigned int line = line_num;

    if (op_code == NULL || op_code[0] == '#')
        return (NULL);

    for (index = 0; index < 8; index++)
    {
        if (strcmp(cmds[index].opcode, op_code) == 0)
        {
            return (cmds[index].f);
        }
    }
    dprintf(STDERR_FILENO, "L%i: unknown instruction %s\n", line,
        op_code);
	exit(EXIT_FAILURE);
}
