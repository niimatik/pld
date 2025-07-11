#include "sword.h"

/**
 * create_sword - Crée une nouvelle épée avec allocation dynamique
 * @length: Longueur de l'épée en centimètres
 * @material: Matériau de l'épée
 * @type: Type d'épée
 *
 * À faire:
 * 1. Allouer la mémoire pour la structure sword_t
 * 2. Initialiser le membre length
 * 3. Allouer et copier la chaîne material
 * 4. Allouer et copier la chaîne type
 * 5. Gérer les cas d'erreur d'allocation
 *
 * Return: Pointeur vers la nouvelle épée ou NULL en cas d'échec
 */
sword_t *create_sword(unsigned int length, const char *material, const char *type)
{
	sword_t *new_sword;
	/* TODO: Allouer la mémoire pour la structure */
	new_sword = malloc(sizeof(sword_t));
	/* TODO: Vérifier si l'allocation a réussi */
	if (new_sword == NULL)
		return (NULL);

	if (type == NULL)
		return (NULL);
	/* TODO: Initialiser le membre length */
	new_sword->length = length;
	/* TODO: Allouer et copier material */
	if (material == NULL)
		return (NULL);

	new_sword->material = malloc(strlen(material) + 1);
	if (new_sword->material == NULL)
	{
		free(new_sword);
		return (NULL);
	}

	new_sword->material = strcpy(new_sword->material, material);
	/* TODO: Allouer et copier type */

	new_sword->type = malloc(strlen(type) + 1);
	if (new_sword->type == NULL)
	{
		free(new_sword->material);
		free(new_sword);
		return (NULL);
	}
	new_sword->type = strcpy(new_sword->type, type);
	/* TODO: Retourner la nouvelle épée */
	return (new_sword);
}

/**
 * print_sword - Affiche les informations d'une épée
 * @sword: Pointeur vers l'épée à afficher
 *
 * À faire:
 * 1. Vérifier que le pointeur n'est pas NULL
 * 2. Afficher length, material et type avec printf
 */
void print_sword(const sword_t *sword)
{
	/* TODO: Vérifier si sword est NULL */
	if (sword == NULL)
		return;

	/* TODO: Afficher les informations de l'épée */
	printf("Type: %s\n", sword->type ? sword->type : "vide");
	printf("Longueur: %d cm\n",sword->length);
	printf("Matériau: %s\n", sword->material ? sword->material : "vide");
}

/**
 * free_sword - Libère la mémoire d'une épée
 * @sword: Pointeur vers l'épée à libérer
 *
 * À faire:
 * 1. Vérifier que le pointeur n'est pas NULL
 * 2. Libérer material
 * 3. Libérer type
 * 4. Libérer la structure
 *
 * ATTENTION: Ordre de libération important!
 */
void free_sword(sword_t *sword)
{
	/* TODO: Vérifier si sword est NULL */
	/* TODO: Libérer material */
	/* TODO: Libérer type */
	/* TODO: Libérer la structure */
	if (sword == NULL)
		return;

	free(sword->material);
	free(sword->type);
	free(sword);
}

/**
 * compare_swords - Compare deux épées par longueur
 * @sword1: Première épée
 * @sword2: Deuxième épée
 *
 * À faire:
 * 1. Vérifier que les pointeurs ne sont pas NULL
 * 2. Comparer les longueurs
 *
 * Return: 1 si sword1 > sword2, -1 si sword1 < sword2, 0 si égales
 */
int compare_swords(const sword_t *sword1, const sword_t *sword2)
{
	/* TODO: Vérifier les pointeurs NULL */
	if (sword1 == NULL || sword2 == NULL)
		return (100);

	/* TODO: Comparer les longueurs et retourner le résultat */
	if (sword1->length < sword2->length)
		return (-1);

	else if (sword1->length > sword2->length)
		return (1);

	return (0);
}
