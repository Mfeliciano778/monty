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
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	tmp = curr->next;
	curr->next->n += curr->n;
	free(curr);
	tmp->prev = NULL;
	(*stack) = tmp;
}
/**
 * sub - subtracts first two elements of a doubly linked list
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	if ((*stack) == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	curr = (*stack);
	if (curr->next)
	{
		curr->next->n -= curr->n;
		curr = curr->next;
		free(curr->prev);
		curr->prev = NULL;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

}
/**
 * divides - divides first two elements of a doubly linked list
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */
void divides(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	if ((*stack) == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	curr = (*stack);
	if (curr->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else if (curr->n == 0 || curr->next->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->n = (*stack)->n / curr->n;
		free(curr);
		(*stack)->prev = NULL;
	}

}
/**
 * mul - multiplies first two elements of a doubly linked list
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	if ((*stack) == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	curr = (*stack);
	if (curr->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->n = (*stack)->n * curr->n;
		free(curr);
		(*stack)->prev = NULL;
	}

}
/**
 * mod - divides first two elements of a doubly linked list
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	if ((*stack) == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	curr = (*stack);
	if (curr->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->n = (*stack)->n % curr->n;
		free(curr);
		(*stack)->prev = NULL;
	}
}
