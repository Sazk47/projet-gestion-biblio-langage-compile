#include <stdio.h>
#include <string.h>

#include "livre.h"
#include "catalogue.h"
#include "recherche.h"
#include "persistance.h"
#include "ui.h"

#define CHEMIN_DONNEES "data/bibliotheque.txt"
#define ANNEE_MIN      1000
#define ANNEE_MAX      2100

/* Retourne 1 si un livre avec le meme titre ET auteur existe deja */
static int doublon_existe(const Bibliotheque *b, const char *titre, const char *auteur)
{
    for (int i = 0; i < b->nb; i++) {
        if (strcmp(b->livres[i].titre, titre) == 0 &&
            strcmp(b->livres[i].auteur, auteur) == 0)
            return 1;
    }
    return 0;
}

int main(void)
{
    Bibliotheque b;
    catalogue_init(&b);
    persistance_charger(&b, CHEMIN_DONNEES);

    int choix = 0;
    do {
        ui_afficher_menu();
        choix = ui_lire_entier("Votre choix : ");

        switch (choix) {
            case 1: {
                Livre nouveau;

                /* Titre : refus si vide */
                ui_lire_chaine("Titre   : ", nouveau.titre, MAX_TITRE);
                if (strlen(nouveau.titre) == 0) {
                    printf("Erreur : le titre ne peut pas etre vide.\n");
                    break;
                }

                /* Auteur : refus si vide */
                ui_lire_chaine("Auteur  : ", nouveau.auteur, MAX_AUTEUR);
                if (strlen(nouveau.auteur) == 0) {
                    printf("Erreur : l'auteur ne peut pas etre vide.\n");
                    break;
                }

                /* Annee : doit etre entre ANNEE_MIN et ANNEE_MAX */
                nouveau.annee = ui_lire_entier("Annee   : ");
                if (nouveau.annee < ANNEE_MIN || nouveau.annee > ANNEE_MAX) {
                    printf("Erreur : annee invalide (entre %d et %d).\n",
                           ANNEE_MIN, ANNEE_MAX);
                    break;
                }

                /* Doublon : meme titre + meme auteur */
                if (doublon_existe(&b, nouveau.titre, nouveau.auteur)) {
                    printf("Erreur : ce livre existe deja dans la bibliotheque.\n");
                    break;
                }

                nouveau.disponible = 1;
                if (catalogue_ajouter(&b, nouveau))
                    printf("Livre ajoute avec succes.\n");
                else
                    printf("Erreur : impossible d'ajouter le livre.\n");
                break;
            }
            case 2:
                catalogue_afficher(&b);
                break;
            case 3:
                /* TODO (B) */
                printf("[3] Rechercher — a implementer\n");
                break;
            case 4:
                /* TODO (B) */
                printf("[4] Emprunter / Rendre — a implementer\n");
                break;
            case 5: {
                if (b.nb == 0) {
                    printf("Aucun livre a supprimer.\n");
                    break;
                }
                catalogue_afficher(&b);
                int index = ui_lire_entier("Numero du livre a supprimer : ");

                /* Validation de l'index avant suppression */
                if (index < 1 || index > b.nb) {
                    printf("Erreur : numero invalide (entre 1 et %d).\n", b.nb);
                    break;
                }

                /* Confirmation */
                char confirm[4];
                ui_lire_chaine("Confirmer la suppression ? (o/n) : ", confirm, sizeof(confirm));
                if (confirm[0] != 'o' && confirm[0] != 'O') {
                    printf("Suppression annulee.\n");
                    break;
                }

                if (catalogue_supprimer(&b, index - 1))
                    printf("Livre supprime avec succes.\n");
                else
                    printf("Erreur : suppression impossible.\n");
                break;
            }
            case 6:
                persistance_sauvegarder(&b, CHEMIN_DONNEES);
                printf("Sauvegarde effectuee. Au revoir !\n");
                break;
            default:
                printf("Choix invalide (entrez un nombre entre 1 et 6).\n");
        }
    } while (choix != 6);

    catalogue_liberer(&b);
    return 0;
}