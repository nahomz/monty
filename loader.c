#include "monty.h"

/**
 *sopen - opens a script file for the montey interpreter
 * if it is possible
 * @name: name of the file
 * Return: the file descriptor and -1 on faliure
 */
FILE *sopen(char *name)
{
	char *path = NULL, *currentdir = NULL;
	FILE *fd;

	if (!name || strlen(name) <= 0)
		return (NULL);

	if (name[0] != '.' && name[0] != '~' && name[0] != '/')
	{
		currentdir = getenv("PWD");
		path = smalloc(strlen(currentdir) + strlen(name) + 4);
		strcpy(path, currentdir);
		strcat(path, "/");
		strcat(path, name);
	}
	else
		path = _strdup(name);

	fd = fopen(path, "r");
	if (!fd)
	{
		dprintf(2, "Error: Can't open file %s\n", name);
		free(path);
		exit(EXIT_FAILURE);
	}
	free(path);

	return (fd);
}
