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
    int line;
    FILE *fptr;
    char *buff = NULL, *l_tok;
    size_t i = 100;
    unsigned int line_num = 1;

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
            is_comm(l_tok);
            printf("%s\n", l_tok);
            line_num++;
        }
    }
    fclose(fptr);
    free(buff);

    return (1);
}

/*int (*is_comm(char *last_tok))
{
    instruction_t commands[] = {
		{"push", push},
		{"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {"NULL", NULL}
    };
    int index;

    if (last_tok == NULL)
        return NULL;
    for (index = 0; index < 8; index++)
    {
        if (strcmp(((commands + index))->opcode, last_tok) == 0)
        {
            return ((commands + index)->f);
        }
    }
    printf("Uknown instruction: %s\n", last_tok);
    exit(EXIT_FAILURE);
    return (NULL);
}*/