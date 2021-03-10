#include "monty.h"
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
		{"sub", sub},
		{"div", divides},
		{"mul", mul},
		{"mod", mod},
		{"nop", NULL},
		{NULL, mem_free}
	};
	int index;

	if (op_code == NULL || op_code[0] == '#')
		return (NULL);

	for (index = 0; index < 10; index++)
	{
		if (strcmp(cmds[index].opcode, op_code) == 0)
		{
			return (cmds[index].f);
		}
	}
	dprintf(STDERR_FILENO, "L%i: unknown instruction %s\n", line_number,
		op_code);
	exit(EXIT_FAILURE);
}
/**
 * mem_free - frees and cleans up the memory
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */
void mem_free(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	free_stack(stack);

	dprintf(STDERR_FILENO, "L%i: unknown instruction\n", line_number);
	exit(EXIT_FAILURE);
}
