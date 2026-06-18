#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persistance.h"
#include "catalogue.h"

int persistance_sauvegarder(const Bibliotheque *b, const char *chemin)
{
    FILE *f = fopen(chemin, "w");
    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir %s en ecriture.\n", chemin);
        return 0;
    }

    for (int i = 0; i < b->nb; i++) {
        fprintf(f, "%s;%s;%d;%d\n",
                b->livres[i].titre,
                b->livres[i].auteur,
                b->livres[i].annee,
                b->livres[i].disponible);
    }

    fclose(f);
    return 1;
}

int persistance_charger(Bibliotheque *b, const char *chemin)
{
    FILE *f = fopen(chemin, "r");
    if (f == NULL)
        return 0;   /* pas d'erreur, juste premier lancement */

    char ligne[256];
    while (fgets(ligne, sizeof(ligne), f)) {
        Livre l;
        ligne[strcspn(ligne, "\n")] = '\0';

        char *titre   = strtok(ligne, ";");
        char *auteur  = strtok(NULL,  ";");
        char *annee   = strtok(NULL,  ";");
        char *dispo   = strtok(NULL,  ";");

        if (!titre || !auteur || !annee || !dispo)
            continue;

        strncpy(l.titre,  titre,  MAX_TITRE  - 1); l.titre[MAX_TITRE   - 1] = '\0';
        strncpy(l.auteur, auteur, MAX_AUTEUR - 1); l.auteur[MAX_AUTEUR - 1] = '\0';
        l.annee      = atoi(annee);
        l.disponible = atoi(dispo);

        catalogue_ajouter(b, l);
    }

    fclose(f);
    return 1;
}