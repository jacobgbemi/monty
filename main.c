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


/**
 * main - entry into interpreter
 * @argc: argc counter
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd, ispush = 0;
	unsigned int line = 1;
	ssize_t n_read;
	char *buffer, *token;
	stack_t *h = NULL;

	if (argc != 2)
		return (usage_error());
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (f_open_error(argv[1]));
	buffer = malloc(sizeof(char) * 10000);
	if (!buffer)
		return (malloc_error());
	n_read = read(fd, buffer, 10000);
	if (n_read == -1)
		f_read_error(buffer, fd);
	else
	{
		token = strtok(buffer, "\n\t\a\r ;:");
		return (loop(token, line, h, ispush));
	}
	free_dlist(&h);
	free(buffer);
	close(fd);
	return (0);
}
