#ifndef PERSISTANCE_H
#define PERSISTANCE_H

#include "livre.h"

int persistance_sauvegarder(const Bibliotheque *b, const char *chemin);

int persistance_charger(Bibliotheque *b, const char *chemin);

#endif
