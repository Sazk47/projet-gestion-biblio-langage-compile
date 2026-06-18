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

                ui_lire_chaine("Titre   : ", nouveau.titre, MAX_TITRE);
                if (strlen(nouveau.titre) == 0) {
                    printf("Erreur : le titre ne peut pas etre vide.\n");
                    ui_pause();
                    break;
                }

                ui_lire_chaine("Auteur  : ", nouveau.auteur, MAX_AUTEUR);
                if (strlen(nouveau.auteur) == 0) {
                    printf("Erreur : l'auteur ne peut pas etre vide.\n");
                    ui_pause();
                    break;
                }

                nouveau.annee = ui_lire_entier("Annee   : ");
                if (nouveau.annee < ANNEE_MIN || nouveau.annee > ANNEE_MAX) {
                    printf("Erreur : annee invalide (entre %d et %d).\n", ANNEE_MIN, ANNEE_MAX);
                    ui_pause();
                    break;
                }

                if (doublon_existe(&b, nouveau.titre, nouveau.auteur)) {
                    printf("Erreur : ce livre existe deja dans la bibliotheque.\n");
                    ui_pause();
                    break;
                }

                nouveau.disponible = 1;
                if (catalogue_ajouter(&b, nouveau))
                    printf("Livre ajouté avec succes.\n");
                else
                    printf("Erreur : impossible d'ajouter le livre.\n");
                ui_pause();
                break;
            }
            case 2:
                catalogue_afficher(&b);
                ui_pause();
                break;
            case 3: {
                char terme[100];
                ui_lire_chaine("Titre ou auteur : ", terme, sizeof(terme));
                if (strlen(terme) == 0) {
                    printf("Erreur : le terme ne peut pas etre vide.\n");
                    ui_pause();
                    break;
                }
                recherche_par_terme(&b, terme);
                ui_pause();
                break;
            }
            case 4: {
                if (b.nb == 0) {
                    printf("Aucun livre dans la bibliotheque.\n");
                    ui_pause();
                    break;
                }
                catalogue_afficher(&b);
                int idx = ui_lire_entier("Numero du livre : ");
                if (idx < 1 || idx > b.nb) {
                    printf("Erreur : numero invalide (entre 1 et %d).\n", b.nb);
                    ui_pause();
                    break;
                }
                recherche_changer_statut(&b, idx - 1);
                ui_pause();
                break;
            }
            case 5: {
                if (b.nb == 0) {
                    printf("Aucun livre a supprimer.\n");
                    ui_pause();
                    break;
                }
                catalogue_afficher(&b);
                int index = ui_lire_entier("Numero du livre a supprimer : ");
                if (index < 1 || index > b.nb) {
                    printf("Erreur : numero invalide (entre 1 et %d).\n", b.nb);
                    ui_pause();
                    break;
                }
                char confirm[4];
                ui_lire_chaine("Confirmer la suppréssion ? (o/n) : ", confirm, sizeof(confirm));
                if (confirm[0] != 'o' && confirm[0] != 'O') {
                    printf("Suppression annulée.\n");
                    ui_pause();
                    break;
                }
                if (catalogue_supprimer(&b, index - 1))
                    printf("Livre supprimé avec succes.\n");
                else
                    printf("Erreur : suppression impossible.\n");
                ui_pause();
                break;
            }
            case 6:
                persistance_sauvegarder(&b, CHEMIN_DONNEES);
                printf("Sauvegarde effectuée. Au revoir !\n");
                break;
            default:
                printf("Choix invalide (entrez un nombre entre 1 et 6).\n");
                ui_pause();
        }
    } while (choix != 6);

    catalogue_liberer(&b);
    return 0;
}