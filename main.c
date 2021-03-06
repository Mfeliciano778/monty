#include "monty.h"

unsigned int line_number = 1;
/**
 * main - function that builds an interpreter for monty bytecode and relies
 * on a unique stack with specific instructions to manipulate it.
 * @argc: the amount of  arguments
 * @argv: the arguments when calling this function
 *
 * Return: 0 if fail, 1 if success
 */
int main(int argc, char *argv[])
{
	stack_t *stack;
	int line;
	FILE *fptr;
	char *buff = NULL, *l_tok;
	size_t i = 0;
	void (*f)(stack_t **, unsigned int);

	stack = NULL;
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((line = getline(&buff, &i, fptr)) != -1)
	{
		if (line != -1)
		{
			l_tok = strtok(buff, " \n\t\v\r\a");
			f = is_comm(l_tok);
			if (f)
				f(&stack, line_number);
			line_number++;
		}
	}
	fclose(fptr);
	free(buff);
	free_stack(&stack);
	return (1);
}
/**
 * free_stack - frees the stack on failure
 * @stack: pointer to the head of the stack
 *
 * Return: Nothing
 */
void free_stack(stack_t **stack)
{
	if ((*stack) == NULL || stack == NULL)
		return;
	else if ((*stack)->next == NULL)
	{
		free((*stack));
	}
	else
	{
		free_stack(&((*stack)->next));
		free((*stack));
	}

}
