#include <stdio.h>
#include <stdlib.h>

#include "catalogue.h"

#define CAPACITE_INITIALE 4

void catalogue_init(Bibliotheque *b)
{
    b->livres   = NULL;
    b->nb       = 0;
    b->capacite = 0;
}

void catalogue_liberer(Bibliotheque *b)
{
    free(b->livres);
    b->livres   = NULL;
    b->nb       = 0;
    b->capacite = 0;
}

int catalogue_ajouter(Bibliotheque *b, Livre livre)
{
    if (b->nb == b->capacite) {
        int nouvelle_capacite = (b->capacite == 0) ? CAPACITE_INITIALE : b->capacite * 2;
        Livre *tmp = realloc(b->livres, nouvelle_capacite * sizeof(Livre));
        if (tmp == NULL) {
            fprintf(stderr, "Erreur : allocation memoire echouee.\n");
            return 0;
        }
        b->livres   = tmp;
        b->capacite = nouvelle_capacite;
    }
    b->livres[b->nb] = livre;
    b->nb++;
    return 1;
}

void catalogue_afficher(const Bibliotheque *b)
{
    if (b->nb == 0) {
        printf("Aucun livre dans la bibliotheque.\n");
        return;
    }
    printf("\n%-4s %-30s %-25s %-6s %s\n", "N°", "Titre", "Auteur", "Annee", "Statut");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < b->nb; i++) {
        printf("%-4d %-30s %-25s %-6d %s\n",
            i + 1,
            b->livres[i].titre,
            b->livres[i].auteur,
            b->livres[i].annee,
            b->livres[i].disponible ? "Disponible" : "Emprunte");
    }
    printf("\n");
}

int catalogue_supprimer(Bibliotheque *b, int index)
{
    if (index < 0 || index >= b->nb) {
        fprintf(stderr, "Erreur : index invalide.\n");
        return 0;
    }
    for (int i = index; i < b->nb - 1; i++) {
        b->livres[i] = b->livres[i + 1];
    }
    b->nb--;
    return 1;
}