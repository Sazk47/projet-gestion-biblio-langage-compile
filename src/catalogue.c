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
    /* TODO (A) : agrandir le tableau avec realloc si b->nb == b->capacite,
     * puis stocker `livre` et incrementer b->nb. */
    (void)b;
    (void)livre;
    return 0;
}

void catalogue_afficher(const Bibliotheque *b)
{
    /* TODO (A) : parcourir b->livres et afficher chaque livre.
     * Squelette minimal pour tester l'execution : */
    if (b->nb == 0) {
        printf("Aucun livre dans la bibliotheque.\n");
        return;
    }
    for (int i = 0; i < b->nb; i++) {
        printf("%d. (a completer)\n", i);
    }
}

int catalogue_supprimer(Bibliotheque *b, int index)
{
    /* TODO (A) : verifier l'index, decaler les elements suivants, decrementer b->nb. */
    (void)b;
    (void)index;
    return 0;
}
