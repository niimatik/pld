#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char * _which(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <programme>\n", argv[0]);
        return NULL;
    }

    const char *path_env = getenv("PATH");
    if (path_env == NULL) {
        fprintf(stderr, "Erreur : PATH non défini.\n");
        return NULL;
    }

    char *path_copy = strdup(path_env);
    if (path_copy == NULL) {
        perror("strdup");
        return NULL;
    }

    char *saveptr = NULL;
    char *rep = strtok_r(path_copy, ":", &saveptr);

    static char buffer[1024];

    while (rep != NULL)
	{
        int ret = snprintf(buffer, sizeof(buffer), "%s/%s", rep, argv[1]);
        if (ret < 0 || ret >= (int)sizeof(buffer))
		{
            fprintf(stderr, "Erreur : chemin trop long\n");
            free(path_copy);
            return NULL;
        }

        if (access(buffer, X_OK) == 0)
		{
            free(path_copy);
            return buffer;
        }

        rep = strtok_r(NULL, ":", &saveptr);
    }

    free(path_copy);
    return NULL;
}

int main(int argc, char **argv)
{
    char *result = _which(argc, argv);
    if (result != NULL)
	{
        printf("Trouvé : %s\n", result);
    }
	else
	{
        if (argc >= 2)
            printf("%s : commande introuvable\n", argv[1]);
        else
            printf("Usage : %s <programme>\n", argv[0]);
    }
    return 0;
}
