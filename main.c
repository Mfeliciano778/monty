#include "lists.h"
/**
 * main - function that builds an interpreter for monty bytecode and relies
 * on a unique stack with specific instructions to manipulate it.
 * @argc: the amount of  arguments
 * @argv: the arguments when calling this function
 *
 * Return 0 if fail, 1 if success
 */
int main(int argc, char *argv[])
{
    stack_t *stack;
    int line;
    FILE *fptr;
    char *buff = NULL, *l_tok;
    size_t i = 100;
    unsigned int line_num = 1;
    void (*f)(stack_t **, unsigned int);

    stack = NULL;
    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        printf("Error: Can't open file <file>\n");
        exit(EXIT_FAILURE);
    }
    while ((line = getline(&buff, &i, fptr)) != -1)
    {
        if (line != -1)
        {
            l_tok = strtok(buff, " \n\t");
            f = is_comm(l_tok);
            if (f != NULL)
                f(&stack, line_num);
            line_num++;
        }
    }
    fclose(fptr);
    free(buff);
    free(stack);
    return (1);
}