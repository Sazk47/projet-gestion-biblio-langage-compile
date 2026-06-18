#ifndef LIVRE_H
#define LIVRE_H

#define MAX_TITRE  100
#define MAX_AUTEUR 100

typedef struct {
    char titre[MAX_TITRE];
    char auteur[MAX_AUTEUR];
    int  annee;
    int  disponible;
} Livre;

typedef struct {
    Livre *livres;
    int    nb;
    int    capacite;   
} Bibliotheque;

#endif 
