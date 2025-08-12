#include "main.h"

extern char **environ;

char *_getenv(const char *name)
{
	int i = 0;
	size_t namelen = strlen(name);
	char *delim = ":";

	while (environ[i])
	{
		if (strncmp(environ[i], name, namelen) == 0
		    && environ[i][namelen] == '=')
		{
			char *token = strtok(environ[i], delim);
        	while (token != NULL)
        	{
           		printf("%s\n", token);
            	token = strtok(NULL, delim);
        	}
		}
		i++;
	}
	return (NULL);
}
