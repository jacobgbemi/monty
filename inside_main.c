#include "monty.h"

/**
 * loop - set the opcode inside while loop
 * and free dlinkedlist pointer.
 * @token: Name of opcode
 * @line: Line number in Monty bytecodes file.
 * @h: dlinkedlist pointer
 * @ispush: status of push data
 * Return: (EXIT_FAILURE) always.
*/
int loop(char *token, unsigned int line, stack_t *h, int ispush)
{
	while (token != NULL)
	{
		if (ispush == 1)
		{
			push(&h, line, token);
			ispush = 0;
			token = strtok(NULL, "\n\t\a\r ;:");
			line++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			ispush = 1;
			token = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (get_op_func(token) != 0)
			{
				get_op_func(token)(&h, line);
			}
			else
			{
				free_dlist(&h);
				printf("L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		token = strtok(NULL, "\n\t\a\r ;:");
	}
	return (0);
}
