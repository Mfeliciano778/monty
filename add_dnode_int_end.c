#include "monty.h"
/**
* add_dnode_int_end - adds node to end of list
* @head: the head node
* @n: number to be added
*
* Return: Nothing
*/
void *add_dnode_int_end(stack_t **head, int n)
{
	stack_t *new_n;

	new_n = malloc(sizeof(stack_t));
	if (!new_n)
	{
		dprintf(STDERR_FILENO, "malloc failed\n");
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	new_n->n = n;
	new_n->next = (*head);
	new_n->prev = NULL;
	if ((*head) != NULL)
		(*head) = new_n;
	else
		(*head) = new_n;
	return (new_n);
}
