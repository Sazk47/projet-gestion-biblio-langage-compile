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
    persistance_charger(&b, CHEMIN_DONNEES);   /* recharge au démarrage */

    int choix = 0;
    do {
        ui_afficher_menu();
        choix = ui_lire_entier("Votre choix : ");

        switch (choix) {
            case 1:
                /* TODO (A) : saisir un Livre via ui_* puis catalogue_ajouter */
                printf("[1] Ajouter — a implementer\n");
                break;
            case 2:
                catalogue_afficher(&b);
                break;
            case 3:
                /* TODO (B) : saisir un terme puis recherche_par_terme */
                printf("[3] Rechercher — a implementer\n");
                break;
            case 4:
                /* TODO (B) : choisir un index puis recherche_changer_statut */
                printf("[4] Emprunter / Rendre — a implementer\n");
                break;
            case 5:
                /* TODO (A) : choisir un index puis catalogue_supprimer */
                printf("[5] Supprimer — a implementer\n");
                break;
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
