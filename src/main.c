#include <stdio.h>

#include "livre.h"
#include "catalogue.h"
#include "recherche.h"
#include "persistance.h"
#include "ui.h"

#define CHEMIN_DONNEES "data/bibliotheque.txt"

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
                ui_lire_chaine("Titre   : ", nouveau.titre,  MAX_TITRE);
                ui_lire_chaine("Auteur  : ", nouveau.auteur, MAX_AUTEUR);
                nouveau.annee      = ui_lire_entier("Annee   : ");
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
                if (catalogue_supprimer(&b, index - 1))
                    printf("Livre supprime avec succes.\n");
                else
                    printf("Erreur : numero invalide.\n");
                break;
            }
            case 6:
                persistance_sauvegarder(&b, CHEMIN_DONNEES);
                printf("Sauvegarde effectuee. Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 6);

    catalogue_liberer(&b);
    return 0;
}