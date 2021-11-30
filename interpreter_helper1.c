#include "monty.h"

/**
 * push - pushes a new element to the stack
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void push(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *new_node, *_head = *head;

	if (token.argc < 1 || !isint(token.args))
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		if (token.args)
			free(token.args);
		exit(EXIT_FAILURE);
	}

	/*Create a node and give it the required values*/
	new_node = smalloc(sizeof(stack_t));
	new_node->n = atoi(token.args);
	if (token.args)
		free(token.args);
	/*if the data mode is stack store the data in front*/
	if (!strcmp(global_vars.data_mod, "stack"))
	{
		new_node->prev = NULL;
		new_node->next = _head;
		if (_head)
			_head->prev = new_node;
		*head = new_node;
	}
	else if (!strcmp(global_vars.data_mod, "queue"))
	{
		if (!_head)
		{
			*head = new_node;
			return;
		}
		/*go to the end of the file*/
		while (_head->next)
			_head = _head->next;
		new_node->prev = _head;
		new_node->next = NULL;
		_head->next = new_node;
	}
}

/**
 * pall - prints all value of the stack starting from top to bottom
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void pall(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *new = *head;

	(void)line_number;
	if (token.args)
		free(token.args);

	while (new)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}


/**
 * pint - prints top element of stack followed by new line
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void pint(stack_t **head, unsigned int line_number, code_args_t token)
{
	if (token.args)
		free(token.args);

	if (*head == NULL)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}


/**
 * pop - removes top element of the stack
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void pop(stack_t **head, unsigned int line_number, code_args_t token)
{
	stack_t *temp = NULL;

	if (token.args)
		free(token.args);
	if (*head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}


/**
 * swap - swaps the top two elements of the stack
 * @head: double pointer to top element of the stack
 * @line_number: current line we are at in the file
 * @token: the number of arguments and the arguments themself
 */
void swap(stack_t **head, unsigned int line_number, code_args_t token)
{
	int temp;

	if (token.args)
		free(token.args);
	if (*head == NULL)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next == NULL)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}
