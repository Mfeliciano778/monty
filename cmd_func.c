#include "monty.h"
/**
 * push - creates/adds a node into a doubly linked list
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *opcode_num;
	int num, i, num_len;


	opcode_num = strtok(NULL, " \n\t\v\r\a");
	if (opcode_num == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num_len = strlen(opcode_num);
	for (i = 0; i < num_len; i++)
	{
		if (isdigit(opcode_num[i]) == 0)
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			break;
		}
	}
	num = atoi(opcode_num);
	add_dnode_int_end(stack, num);
}
/**
 * pall - prints all elements of a doubly linked list
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	if ((*stack) == NULL || stack == NULL)
		return;
	curr = (*stack);
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
	line_number++;
}
/**
 * pint - prints the first value a doubly linked list
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	curr = (*stack);
	if ((*stack) == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", curr->n);
}
/**
 * pop - removes top two elements a doubly linked list
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	if ((*stack) == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
			exit(EXIT_FAILURE);
	}

		curr = (*stack);
	(*stack) = curr->next;
	free(curr);

	if ((*stack) != NULL)
	{
		(*stack)->prev = NULL;

	}
}
/**
 * swap - swaps first two elements of a doubly linked list
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
        stack_t *tmp;

        if ((*stack) == NULL || stack == NULL)
        {
                dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        curr = (*stack);
        tmp = curr->next;

	if (tmp)
	{
		if (tmp->next)
		{
		curr->next = tmp->next;
		tmp->next->prev = curr;
		curr->prev = tmp;
		tmp->prev = NULL;
		tmp->next = curr;
		(*stack) = tmp;
		}

		else
		{
			curr->next = NULL;
			curr->prev = tmp;
			tmp->prev = NULL;
			tmp->next = curr;
			(*stack) = tmp;
		}
	}

	else
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
	}
}
