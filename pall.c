/**
* f_pall - Print all values in the stack
* @stack: Doulble poineter to the top of the stack
* @line_num: The line of the file the command was found
*/

void f_pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
