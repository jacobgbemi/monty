#include "monty.h"

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
