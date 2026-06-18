#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persistance.h"
#include "catalogue.h"

int persistance_sauvegarder(const Bibliotheque *b, const char *chemin)
{
    FILE *f = fopen(chemin, "w");
    if (f == NULL) {
        fprintf(stderr, "Erreur : impossible d'ouvrir '%s' en ecriture.\n", chemin);
        return 0;
    }

    for (int i = 0; i < b->nb; i++) {
        if (fprintf(f, "%s;%s;%d;%d\n",
                b->livres[i].titre,
                b->livres[i].auteur,
                b->livres[i].annee,
                b->livres[i].disponible) < 0) {
            fprintf(stderr, "Erreur : ecriture echouee sur '%s'.\n", chemin);
            fclose(f);
            return 0;
        }
    }

    fclose(f);
    printf("Bibliotheque sauvegardee dans '%s'.\n", chemin);
    return 1;
}

int persistance_charger(Bibliotheque *b, const char *chemin)
{
    FILE *f = fopen(chemin, "r");
    if (f == NULL)
        return 0;  /* fichier absent au premier lancement silencieux */

    char ligne[256];
    int nb_charges = 0;
    while (fgets(ligne, sizeof(ligne), f)) {
        Livre l;
        ligne[strcspn(ligne, "\n")] = '\0';

        char *titre  = strtok(ligne, ";");
        char *auteur = strtok(NULL,  ";");
        char *annee  = strtok(NULL,  ";");
        char *dispo  = strtok(NULL,  ";");

        if (!titre || !auteur || !annee || !dispo)
            continue;  /* ligne corrompue on saute silencieusement */

        strncpy(l.titre,  titre,  MAX_TITRE  - 1); l.titre[MAX_TITRE   - 1] = '\0';
        strncpy(l.auteur, auteur, MAX_AUTEUR - 1); l.auteur[MAX_AUTEUR - 1] = '\0';
        l.annee      = atoi(annee);
        l.disponible = atoi(dispo);

        catalogue_ajouter(b, l);
        nb_charges++;
    }

    fclose(f);
    return nb_charges;
}