#include "monty.h"
/**
 * opcode_functions - operations to perform
 * @command: comand
 * @stack: stack
 * @line: line read
 * Return: nothing
 */
void opcode_functions(char *command, stack_t **stack, unsigned int line)
{
	int j;

	instruction_t operations[] = {{"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", my_div}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl},
		{NULL, NULL}};

	for (j = 0; operations[j].opcode != NULL; j++)
	{
		if (my_cmp(command, operations[j].opcode) == 1)
		{
			operations[j].f(stack, line);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, command);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
/**
 * pall - prints the data of all nodes in stack
 * @stack: pointer to the head node pointer of stack
 * @line: the line number
 *
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int line)
{
	stack_t *tmp;
	(void)line;

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pint - prints the value at the top of the stack.
 * @stack: Stack list
 * @line_number: Number of the line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
		fprintf(stderr, "%d\n", (*stack)->n);
}
/**
 * pop - removes the top element of the stack.
 * @stack: Stack list
 * @line_number: Number of the line
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
}
/**
 * swap - swaps the top two elements of the stack
 *
 * @head: head of the linked list
 * @line: line number
 * Return: no return
 */
void swap(stack_t **head, unsigned int line)
{
	int i = 0;
	stack_t *tmp = NULL;

	tmp = *head;

	for (; tmp != NULL; tmp = tmp->next, i++)
		;

	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	tmp->prev = *head;
	(*head)->next = tmp;
	(tmp)->prev = NULL;
	tmp->next->prev = tmp;
	tmp->prev = NULL;
}
