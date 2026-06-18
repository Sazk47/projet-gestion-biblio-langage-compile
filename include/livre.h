#ifndef LIVRE_H
#define LIVRE_H

/* Structures partagées entre tous les modules (A + B).
 * À valider ensemble avant de coder : ne plus modifier sans prévenir l'autre. */

#define MAX_TITRE  100
#define MAX_AUTEUR 100

typedef struct {
    char titre[MAX_TITRE];
    char auteur[MAX_AUTEUR];
    int  annee;
    int  disponible;   /* 1 = disponible, 0 = emprunté */
} Livre;

typedef struct {
    Livre *livres;     /* tableau dynamique (malloc/realloc) */
    int    nb;         /* nombre de livres stockés */
    int    capacite;   /* taille allouée */
} Bibliotheque;

#endif /* LIVRE_H */
