#include "monty.h"
#include <stdio.h>

/**
 * main - main function
 * @argc: argument count
 * @argv: vector count
 * Return: success or failure
 */
int main(int argc, char *argv[])

{
	FILE *FD;

	if (argc != 2)
	{
		fprintf(stderr, "USUSAGE: monty file");
		return (EXIT_FAILURE);
	}
	FD = fopen(argv[1], "r");
	if (!FD)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_line(FD);
	fclose(FD);
	return (0);
}

/**
 * read_line - gets line from file pointer
 * @file: file pointer
 * Return: nothing
 */
void read_line(FILE *file)
{
	size_t size = 10000;
	char line[10000];
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *command, *argument, *valid = NULL;

	while (fgets(line, size, file) != NULL)
	{
		line_number += 1;
		command = strtok(line, " \n\t\r");
		if (command == NULL || *command == '#')
			continue;
		argument = strtok(NULL, " \n\t\r");
		if (my_cmp(command, "push") == 1)
		{
			valid = valid_arg(argument);
			if (!valid)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, line_number, valid);
			free(valid);
			continue;
		}
		opcode_functions(command, &stack, line_number);
	}
}
/**
 * push - pushes a node to the top of stack
 * @stack: pointer to the head node pointer of stack
 * @line: the line number
 * @arg: arguments
 * Return: Nothing.
 */

void push(stack_t **stack, unsigned int line, char *arg)
{
	stack_t *node = NULL;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: Error stack not found\n", line);
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	node->n = atoi(arg);
	node->prev = NULL;
	node->next = *stack;
	if (*stack)
		(*stack)->prev = node;

	(*stack) = node;
}
/**
 * free_stack - frees a list.
 * @head: head of list
 * Description: free list
 * Return: Nothing
 */
void free_stack(stack_t **head)
{

	stack_t *temp = NULL;

	if (head == NULL || *head == NULL)
		return;

	while (*head != NULL)
	{
		temp = (*head)->next;
		free(*head);
		(*head) = temp;
	}
}
/**
 * valid_arg - checks if argument is a digit
 * @arg: argument
 * Return: integer
 */
char *valid_arg(char *arg)
{
	int i = 0;
	char *is_digit;

	if (!arg || arg[0] == '\0')
		return (NULL);
	is_digit = malloc((strlen(arg) + 1) * sizeof(char));
	if (!is_digit)
		return (NULL);
	if (arg[0] == '-' && isdigit(arg[1]))
	{
		is_digit[0] = '-';
		i = 1;
	}
	else if (!isdigit(arg[0]))
	{
		free(is_digit);
		return (NULL);
	}
	for ( ; arg[i]; i++)
	{
		if (!isdigit(arg[i]))
			break;
		if (isdigit(arg[i]))
			is_digit[i] = arg[i];
	}
	is_digit[i] = '\0';
	return (is_digit);
}
