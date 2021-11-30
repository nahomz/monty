#include "monty.h"

/**
 * add - adds top two elements of the stack
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void add(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *_head = *head, *tmp = NULL;

	if (token.args)
		free(token.args);

	/*check if there are nodes to be added*/
	if (!_head)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(_head->next))
	{

		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*add the nodes and store the sum in the second node*/
	_head->next->n += _head->n;

	/*Remove the top node after storign the sum in the second and move the head*/
	tmp = _head->next;
	_head->next->prev = NULL;
	free(_head);
	*head = tmp;
}


/**
 * nop - doesn't do anything
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void nop(stack_t **head, unsigned int line_number, code_args_t token)
{
	(void)head;
	(void)line_number;
	if (token.args)
		free(token.args);
}


/**
 * sub - subtracts top element of the stack from second top element
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void sub(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *_head = *head, *tmp = NULL;

	if (token.args)
		free(token.args);
	/*check if there are nodes to be substracted*/
	if (!_head)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(_head->next))
	{

		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	_head->next->n -= _head->n;
	/*
	*Remove the top node after storing the difference in the second
	*and move the head
	*/
	tmp = _head->next;
	_head->next->prev = NULL;
	free(_head);
	*head = tmp;
}


/**
 * div_m - divides second top element by the top element.
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void div_m(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *_head = *head, *tmp = NULL;

	if (token.args)
		free(token.args);
	/*check if there are nodes to be divided*/
	if (!_head)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(_head->next))
	{

		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*Handle division by zero*/
	if (_head->n == 0)
	{

		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*
	*Find the division of the second node by the first node
	*and store it in the second node
	*/
	_head->next->n = _head->next->n / _head->n;
	/*
	*Remove the top node after storing the dividend
	*in the second and move the head
	*/
	tmp = _head->next;
	_head->next->prev = NULL;
	free(_head);
	*head = tmp;
}


/**
 * mult - multiplies top two elements of the stack
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void mult(stack_t **head, unsigned int line_number, code_args_t token)
{

	stack_t *_head = *head, *tmp = NULL;

	if (token.args)
		free(token.args);
	/*check if there are nodes to be multiplied*/
	if (!_head)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(_head->next))
	{

		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	_head->next->n = _head->next->n * _head->n;
	/*
	*Remove the top node after storing the difference
	*in the second and move the head
	*/
	tmp = _head->next;
	_head->next->prev = NULL;
	free(_head);
	*head = tmp;
}
