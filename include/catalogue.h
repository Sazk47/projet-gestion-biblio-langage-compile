#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "livre.h"

/* Module CATALOGUE — Personne A
 * Gestion mémoire + CRUD de base (ajouter, afficher, supprimer). */

/* Initialise une bibliothèque vide. */
void catalogue_init(Bibliotheque *b);

/* Libère toute la mémoire allouée. */
void catalogue_liberer(Bibliotheque *b);

/* Ajoute un livre (redimensionne le tableau si besoin).
 * Retourne 1 si succès, 0 sinon. */
int catalogue_ajouter(Bibliotheque *b, Livre livre);

/* Affiche tous les livres. */
void catalogue_afficher(const Bibliotheque *b);

/* Supprime le livre à l'index donné.
 * Retourne 1 si succès, 0 si index invalide. */
int catalogue_supprimer(Bibliotheque *b, int index);

#endif /* CATALOGUE_H */
