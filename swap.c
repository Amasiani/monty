#include "monty.h"

/**
* f_swap - adds the top two elements of the stack.
* @head: stack head
* @line_number: counter
*
* Return: None
*/

void f_swap(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->head;
		len++;
	}
	if (len < 2)
	{
	
	}
}
