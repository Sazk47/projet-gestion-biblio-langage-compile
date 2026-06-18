#ifndef RECHERCHE_H
#define RECHERCHE_H

#include "livre.h"

/* Module RECHERCHE — Personne B
 * Recherche partielle + emprunter/rendre.
 * Interface proposée par A, ajustable par B. */

/* Affiche les livres dont le titre OU l'auteur contient `terme`
 * (recherche partielle). Retourne le nombre de résultats. */
int recherche_par_terme(const Bibliotheque *b, const char *terme);

/* Bascule le statut disponible/emprunté du livre à l'index donné.
 * Retourne 1 si succès, 0 si index invalide. */
int recherche_changer_statut(Bibliotheque *b, int index);

#endif /* RECHERCHE_H */
