#include "monty.h"

globals global_vars = {{'\0', '\0', '\0', '\0', '\0', '\0'}, NULL, NULL, NULL};

/**
 * clean_up - Clean up during exit
 */
void clean_up(void)
{
	if (global_vars.line)
		free(global_vars.line);
	if (global_vars.head)
		freedll(global_vars.head);
	/*Close the file before exiting*/
	if (global_vars.fd)
		fclose(global_vars.fd);
}

/**
 * main - entry point of the intepreter
 * @argc: argument count
 * @argv: argument list
 * Return: 0 on success, and error messages as specified
 * in error.h
 */
int main(int argc, char **argv)
{
	ssize_t read_stat = -1;
	size_t buffsize = 0;
	int reading = 1, line_number = 1;

	atexit(clean_up);

	/*check if there is correct argument number*/
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*safely open the file*/
	global_vars.fd = sopen(argv[1]);
	/*Set the default data structure mode to stack*/
	strcpy(global_vars.data_mod, "stack");

	/* Check if the command per line is correct and excute*/
	while (reading)
	{
		read_stat = getline(&global_vars.line, &buffsize, global_vars.fd);
		if (read_stat == -1)
		{
			reading = 0;
			break;
		}
		interpret(global_vars.line, line_number, &global_vars.head);
		line_number += 1;
	}
	exit(EXIT_SUCCESS);
}
