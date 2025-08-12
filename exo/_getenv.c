#include "main.h"

extern char **environ;

char *_getenv(const char *name)
{
	int i = 0;
	size_t namelen = strlen(name);

	while (environ[i])
	{
		if (strncmp(environ[i], name, namelen) == 0
		    && environ[i][namelen] == '=')
		{
			return environ[i] + namelen + 1;
		}
		i++;
	}
	return (NULL);
}
