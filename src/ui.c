#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"

void ui_afficher_menu(void)
{
    printf("\n=== BIBLIOTHEQUE ===\n");
    printf("1. Ajouter un livre\n");
    printf("2. Afficher tous les livres\n");
    printf("3. Rechercher\n");
    printf("4. Emprunter / Rendre\n");
    printf("5. Supprimer un livre\n");
    printf("6. Sauvegarder et quitter\n");
    printf("Votre choix : ");
}

void ui_lire_chaine(const char *invite, char *dest, int taille)
{
    printf("%s", invite);
    if (fgets(dest, taille, stdin) == NULL) {
        dest[0] = '\0';
        return;
    }
    dest[strcspn(dest, "\n")] = '\0';
}

int ui_lire_entier(const char *invite)
{
    char buf[32];
    ui_lire_chaine(invite, buf, sizeof(buf));
    return atoi(buf);
}