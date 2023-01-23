#include "monty.h"

/**
* _push - push int to a stack
* @stack: linked lists for a monty stack
* @line_number: number of line opcode occurs on
*/

void _push(stack_t **stack, __attribute__ ((unused))unsigned int  line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = var_global.push_arg;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack->prev = top);
	*stack = top;
}

/**
* _pall - print all function
* @stack: pointer to linked list stack
* @line_number: number of line opciode occurs on
*/

void _pall(stack_t *8stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
* _pint - print int a top of stack
* @stack: pointer to linked list stack
* @line_number: number of line opcode occurs on
*/

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: caan't print, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
* _pop - remove element from list
* @stack: pointer to the first node
* @line_number: integer
*
* Return: void
*/

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(node);
}

/**
* free_dlistint - free a list
* @head: pointer to first node
*
* Return: 0
*/
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
