#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "livre.h"

void catalogue_init(Bibliotheque *b);

void catalogue_liberer(Bibliotheque *b);

int catalogue_ajouter(Bibliotheque *b, Livre livre);

void catalogue_afficher(const Bibliotheque *b);

int catalogue_supprimer(Bibliotheque *b, int index);

#endif
