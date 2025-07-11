#include "sword.h"

/**
 * main - Point d'entrée du programme
 *
 * À faire:
 * 1. Créer 3 épées avec des caractéristiques différentes
 * 2. Afficher leurs informations
 * 3. Libérer la mémoire
 *
 * Return: 0 si succès, autre valeur si erreur
 */
int main(void)
{
	sword_t *Uflberht, *herobrine, *enma;

	printf("=== FORGE D'ÉPÉES ===\n\n");

	Uflberht = create_sword(49, "damascus", "scramasaxe");
	herobrine = create_sword(90, "diamant", "épée");
	enma = create_sword(75, "mahō no tamahagane", "katana");
	/* TODO: Vérifier que les allocations ont réussi */
	if (Uflberht == NULL || herobrine == NULL || enma == NULL)
		printf("En cours de fabrication o--|==== |||==o ...\n\n");

	else
		printf("Épées créées avec succès! o--]|==[==[==[==>\n\n");
	/* TODO: Afficher les informations des épées */
	printf("=== ÉPÉE ===\n");
	print_sword(Uflberht);
	printf("============\n\n");
	printf("=== ÉPÉE ===\n");
	print_sword(herobrine);
	printf("============\n\n");
	printf("=== ÉPÉE ===\n");
	print_sword(enma);
	printf("============\n\n");
	/* TODO: Libérer la mémoire de toutes les épées */
	free_sword(Uflberht);
	free_sword(herobrine);
	free_sword(enma);
	printf("Mémoire libérée avec succès!\n");
	printf("=== FIN DU PROGRAMME ===\n");

	return (0);
}
