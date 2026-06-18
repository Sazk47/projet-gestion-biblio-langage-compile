#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "catalogue.h"

#define CAPACITE_INITIALE 4
#define COL_TITRE         28
#define COL_AUTEUR        23

/* Affiche une chaine tronquee a max caracteres avec padding */
static void afficher_col(const char *str, int max)
{
    int len = (int)strlen(str);
    if (len > max) {
        printf("%-.*s... ", max - 3, str);
    } else {
        printf("%-*s ", max, str);
    }
}

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

    printf("\n%-4s %-*s %-*s %-6s %s\n",
        "N°", COL_TITRE, "Titre", COL_AUTEUR, "Auteur", "Annee", "Statut");
    printf("------------------------------------------------------------------------\n");

    int nb_disponibles = 0;
    for (int i = 0; i < b->nb; i++) {
        printf("%-4d ", i + 1);
        afficher_col(b->livres[i].titre,  COL_TITRE);
        afficher_col(b->livres[i].auteur, COL_AUTEUR);
        printf("%-6d %s\n",
            b->livres[i].annee,
            b->livres[i].disponible ? "Disponible" : "Emprunte");
        if (b->livres[i].disponible)
            nb_disponibles++;
    }

    printf("------------------------------------------------------------------------\n");
    printf("%d livre(s) au total  |  %d disponible(s)  |  %d emprunte(s)\n",
        b->nb, nb_disponibles, b->nb - nb_disponibles);
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