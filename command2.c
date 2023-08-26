#include "monty.h"
/**
 * add - function add two integer
 * @stack: Stack list
 * @line_number: Number of the line
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	pop(stack, line_number);
}
/**
 * nop - function void
 * @stack: Stack list
 * @line_number: Number of the line
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub - subtracts the top element of the stack from the second.
 * @stack: Stack list
 * @line_number: Number of line
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sub = 0;

	if (!tmp || !tmp->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	sub = tmp->next->n - tmp->n;
	tmp->next->n = sub;
	pop(stack, line_number);
}
/**
 * my_div - function div two number
 * @stack: Stack list
 * @line_number: Number of the line
 * Return: nothing
 */
void my_div(stack_t **stack, unsigned int line_number)
{
	stack_t *curerent = NULL;
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	div = curerent->next->n / curerent->n;
	curerent->next->n = div;
	pop(stack, line_number);
}
/**
 * mul - multiplies the second top with the top element.
 * @stack: Stack.
 * @line_number: Number of line
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int mul = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	mul = current->next->n * current->n;
	pop(stack, line_number);
	current->next->n = mul;
}
