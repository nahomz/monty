#include "monty.h"


/**
 * get_op_func -  selects the correct function to
 * perform the operation asked by the commad
 * @command: input string
 * Return: pointer to a function
 */
void (*get_op_func(char *command))(stack_t **, unsigned int, code_args_t)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_m},
		{"mul", mult},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue},
		{"stack", stack},
	};
	int i = 0;
	const int num_of_cmds = 17; /*Number of commands in ops*/

	/*Handle incase the line is comment*/
	if (command[0] == '#')
		return (nop);
	/*Handle the case incase the line is empty*/
	if (!strcmp(command, "\n"))
		return (nop);

	while (i < num_of_cmds)
	{
		if (strcmp(ops[i].opcode, command) == 0)
			return (ops[i].func);
		i++;
	}

	return (NULL);
}

/**
 * interpret - iterprets a singe line code
 * according the rules  specified by the monty
 * language
 * @line: a string holding a command
 * @line_number: the line number where the string is found
 * @head: a double pointer to the stack holding all the
 * information about the program
 */
void interpret(char *line, int line_number, stack_t **head)
{
	char *cmd = NULL, *tmp = NULL, *opcode = NULL;
	void (*func)(stack_t **, unsigned int, code_args_t) = NULL;
	code_args_t token;

	trims(&cmd, line);
	token.argc = 0, token.args = NULL;
	/* remove new line character if its length is more than */
	if (strlen(cmd) > 1)
		cmd[strlen(cmd) - 1] = '\0';
	/*Parse the command name and the arguments into the token*/
	tmp = strtok(cmd, " ");
	opcode = _strdup(tmp);
	tmp = strtok(NULL, " ");
	if (tmp)
	{
		token.args = _strdup(tmp);
		token.argc += 1;
		tmp = strtok(NULL, " ");
		if (tmp)
			token.argc += 1;
	}
	free(cmd);
	/*Get the corrspondng fuction to the opcode and callit*/
	func = get_op_func(opcode);
	if (func)
	{
		free(opcode);
		func(head, line_number, token);
	}
	else
	{
		/*print an error in the case where there is no commad  the opcode*/
		dprintf(2, "L%u: unknown instruction %s\n", line_number, opcode);
		free(opcode);
		if (token.args)
			free(token.args);
		exit(EXIT_FAILURE);
	}
}
