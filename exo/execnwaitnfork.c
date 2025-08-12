#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;
	pid_t pid;

	while (i < 5)
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
            char *args[] = { "ls", "-l", "/tmp", NULL };

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
		i++;
	}
	return (0);
}
