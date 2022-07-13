#include "monty.h"

/**
 * usage_error - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - Prints file opening error messages w/ file name.
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * f_read_error - if read error, free buffer.
 * @buffer: address of file failed to read
 * @fd: status of file open
 * Return: (EXIT_FAILURE) always.
 */
int f_read_error(char *buffer, int fd)
{
	free(buffer);
	close(fd);
	return (EXIT_FAILURE);
}

/**
 * get_op_error - Prints get operation error messages
 * and free dlinkedlist pointer.
 * @token: Name of opcode failed to get
 * @line: Line number in Monty bytecodes file where error occured.
 * @h: dlinkedlist pointer
 * Return: (EXIT_FAILURE) always.
 */
int get_op_error(char *token, unsigned int line, stack_t **h)
{
	free_dlist(h);
	printf("L%d: unknown instruction %s\n", line, token);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
