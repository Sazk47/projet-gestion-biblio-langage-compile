#ifndef PERSISTANCE_H
#define PERSISTANCE_H

#include "livre.h"

/* Module PERSISTANCE — Personne B
 * Sauvegarde / chargement fichier texte.
 * Format d'une ligne : titre;auteur;annee;disponible
 * Interface proposée par A, ajustable par B. */

/* Sauvegarde la bibliothèque dans le fichier.
 * Retourne 1 si succès, 0 sinon. */
int persistance_sauvegarder(const Bibliotheque *b, const char *chemin);

/* Charge les livres depuis le fichier au démarrage.
 * Retourne le nombre de livres chargés (0 si fichier absent). */
int persistance_charger(Bibliotheque *b, const char *chemin);

#endif /* PERSISTANCE_H */
