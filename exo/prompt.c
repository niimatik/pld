#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char *argv = NULL;
	size_t argc = 0;
	char *delim = " ";

	printf("$ ");
	if (getline(&argv, &argc, stdin) != -1)
	{
		char *token = strtok(argv, delim);
		while (token != NULL)
		{
    		printf("%s\n", token);
			token = strtok(NULL, delim);
		}
	}
}
