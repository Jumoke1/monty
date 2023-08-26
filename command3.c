#include "monty.h"
/**
 * mod - computes the rest of the division of the second top element
 * @stack: Stack.
 * @line_number: Number of line
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *curerent = NULL;
	int modd = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	curerent = *stack;
	modd = curerent->next->n % curerent->n;
	curerent->next->n = modd;
	pop(stack, line_number);
}
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: Stack.
 * @line_number: Number of line
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;
	if (num < 0 || num > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	putchar(num);
	putchar(10);
}
/**
 * pstr - Print a string.
 * @stack: stack
 * @line_number: Number of line
 * @Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current && current->n)
	{
		if (current->n < 32 || current->n > 127)
			break;
		printf("%c", current->n);
		current = current->next;
	}
	putchar(10);
}
/**
  *rotl - rotates the stack to the top
  *@head: stack head
  *@counter: line_number
  *Return: nothing
 */
void rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
/**
 * my_cmp - compares strings
 * @src: source string
 * @str: string to compare
 * Return: int
 */
int my_cmp(const char *src, const char *str)
{
	int i;

	if (src == NULL || str == NULL)
		return (-1);
	for (i = 0; src[i] != '\0'; i++)
	{
		if (src[i] == str[i])
		{
			if (str[i + 1] == '\0')
				return (1);
			continue;
		}
		return (-1);
	}
	if (str[i] == '\0')
		return (1);
	return (-1);
}
