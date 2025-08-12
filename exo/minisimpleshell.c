#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
    char *argv = NULL;
    size_t argc = 0;
	pid_t pid;

    printf("$ ");
    if (getline(&argv, &argc, stdin) != -1)
    {
		pid = fork();

		if (pid < 0)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			char *chemin = "/bin/ls";
			char *args[] = { argv, NULL };

			if (execve(chemin, args, NULL) == -1)
    		{
        		perror("Error:");
				exit(EXIT_FAILURE);
    		}
		}
		else
		{
			int statut;
            waitpid(pid, &statut, 0);
		}
    }
}
