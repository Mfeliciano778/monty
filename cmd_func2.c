#include "monty.h"
/**
 * add - adds first two elements of a doubly linked list
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *curr, *tmp;

	curr = (*stack);
	if (curr == NULL || stack == NULL || curr->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	tmp = curr->next;
	curr->next->n += curr->n;
	free(curr);
	tmp->prev = NULL;
	(*stack) = tmp;
}
