#ifndef RECHERCHE_H
#define RECHERCHE_H

#include "livre.h"

int recherche_par_terme(const Bibliotheque *b, const char *terme);

int recherche_changer_statut(Bibliotheque *b, int index);

#endif
