#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - Loop through given file and run given opcode command
* @argc: The number of arguments passed to program
* @argv: The string passed to the program
*
* Return: 1 if reaches end of the file, else exit with EXIT_FAILURE
* if opcode fails
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char *content;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	size_t size = 0;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
