#include "monty.h"

/**
 * rotr - rotates stack to the bottom
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void rotr(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *_head = *head, *bottom = NULL;

	if (token.args)
		free(token.args);
	(void)(line_number);
	if (!_head)
		return;
	if (!(_head->next))
		return;

	/*Go to the end of the list*/
	while (_head->next)
		_head = _head->next;

	/*Store the bottom*/
	bottom = _head;

	/*Detach the it from the last*/
	bottom->prev->next = NULL;

	/*set the head next to it and the prev empty*/
	bottom->next = *head;
	bottom->prev = NULL;

	/*Set the bottom to now be the head*/
	*head = bottom;
}

/**
 * queue - changes the push mode to a queue by changind the data
 * structure mod to a queue
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void queue(stack_t **head, unsigned int line_number, code_args_t token)
{
	strcpy(global_vars.data_mod, "queue");

	(void)head;
	(void)line_number;
	if (token.args)
		free(token.args);
}

/**
 * stack - changes the push mode to a stack by changing the data
 * structure mode to a stack
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void stack(stack_t **head, unsigned int line_number, code_args_t token)
{
	strcpy(global_vars.data_mod, "stack");

	(void)head;
	(void)line_number;
	if (token.args)
		free(token.args);
}
