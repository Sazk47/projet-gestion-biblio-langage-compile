#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ui.h"

void ui_afficher_menu(void)
{
    system("clear");
    printf("=== BIBLIOTHEQUE ===\n");
    printf("1. Ajouter un livre\n");
    printf("2. Afficher tous les livres\n");
    printf("3. Rechercher\n");
    printf("4. Emprunter / Rendre\n");
    printf("5. Supprimer un livre\n");
    printf("6. Sauvegarder et quitter\n");
}

int ui_lire_entier(const char *invite)
{
    int valeur = 0;
    printf("%s", invite);
    if (scanf("%d", &valeur) != 1) {
        valeur = -1;
    }
    while (getchar() != '\n' && !feof(stdin)) { /* vide le buffer */ }
    return valeur;
}

void ui_lire_chaine(const char *invite, char *dest, int taille)
{
    printf("%s", invite);
    if (fgets(dest, taille, stdin)) {
        dest[strcspn(dest, "\n")] = '\0';
    } else {
        dest[0] = '\0';
    }
}