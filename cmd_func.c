#include "lists.h"

void push(stack_t **stack, unsigned int line_number)
{
    char *opcode_num;
    int num, i, num_len;


    opcode_num = strtok(NULL, " \n\t");
    if (opcode_num == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
    }
    num_len = strlen(opcode_num);
    for(i = 0; i < num_len; i++)
    {
        if(isdigit(opcode_num[i]) == 0)
        {
            dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_num);
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

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *curr;

    curr = (*stack);
    if ((*stack) == NULL || stack == NULL)
        return;
    while(curr)
    {
        printf("%d\n", curr->n);
        curr = curr->next;
    }
    line_number++;
}

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

void swap(stack_t **stack, unsigned int line_number)
{
    (*stack) = NULL;
    line_number++;
    printf("swap");
}
