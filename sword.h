#ifndef SWORD_H
#define SWORD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct sword_s - Structure représentant une épée
 * @length: Longueur de l'épée en centimètres
 * @material: Matériau de l'épée (acier, fer, etc.)
 * @type: Type d'épée (sabre, épée, claymore, etc.)
 */
typedef struct sword_s
{
	unsigned int length;
	char *material;
	char *type;
} sword_t;

/* Prototypes des fonctions */
sword_t *create_sword(unsigned int length, const char *material, const char *type);
void print_sword(const sword_t *sword);
void free_sword(sword_t *sword);
int compare_swords(const sword_t *sword1, const sword_t *sword2);

#endif /* SWORD_H */
