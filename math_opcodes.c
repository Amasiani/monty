#include "monty.h"

/**
* add - Add the top twoo values of the stack, store the sum in
* the second postion
* @stack: Double pointer to the top of the stack
* @line_num: The line the command was found in the monty file
*/

void add(stack_t **stack, unsigned int line_num)
{
	stack_t *walker;

	walker = *stack;
	if (walker == NULL || walker->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		walker->next->n += walker->n;
		pop(stack, line_num);
	}
}

/**
* sub - Subtract the top element of the stack from the second
* and store result in the second position, set *stack to the second  node
* and remove top node
* @stack: Double pointer to the top of the stack
* @line_num: The line the command was found in the monty file
*/

void sub(stack_t **stack, unsigned int line_num)
{
	stack_t *walker;

	walker = *stack;
	if (walker == NULL || walker->next == NULL)
	{
		printf("L%u: caan't sub, stack too short\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		walker->next->n -= walker->n;
		pop(stack, line_num);
	}
}

/**
* _div - Divide the second element of the stack by the first element of the
* stack, store result in second position, set stack to the second  node
* and remove top node
* @stack: Double pointer to the top of the stack
* @line_num: The line the command was found in the monty file
*/

void _div(stack_t **stack, unsigned int line_num)
{
	stack_t *walker;

	walker = *stack;
	if (walker == NULL || walker->next || NULL)
	{
		printf("L%u: can't div, stack too short\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		walker->next->n /= walker->n;
		pop(stack, line_num);
	}
}

/**
* mul - Multiple the top two values of the stock, store result in second
* position, set 8stack to second node, and remove top node
* @stack: Double pointer to the top of the node
* @line_num: The ine the command was found in the monty file
*/

void mul(stack_t **stack, unsigned int line_num)
{
	stack_t *walker;

	walker = *stack;
	if (walker == NULL || walker->next == NULL)
	{
		printf("L%u: can't mul, stack to short\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		walker->next->n *= walker->n;
		pop(stack, line_num);
	}
}

/**
* mod - Od the second element of the stack by the first element of the stack,
* store the result in second position, set *stack to second node
* and remove top node
* @stack: Double pointer to the top of the stack
* @line_num: The line the command was found in te monty file
*/

void mod(stack_t **stack, unsigned int line_num)
{
	stack_t *walker;

	walker = *stack;
	if (walker == NULL || walker->next == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (walker != NULL && walker->n == 0 && ret_and_q.opcode_return != 1)
	{
		printf("L%u: division by zero\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		walker->next->n %= walker->n;
		pop(stack, line_num);
	}
}
