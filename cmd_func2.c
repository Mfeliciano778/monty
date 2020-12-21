#include "lists.h"

void add(stack_t **stack, unsigned int line_number)
{
    (*stack) = NULL;
    line_number++;
    printf("add");
}

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
