#include "lists.h"

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
