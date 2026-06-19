#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "recherche.h"

/* convertit src en minuscules dans dst, pour la recherche insensible pour casse */
static void to_lower(char *dst, const char *src, int taille)
{
    int i;
    for (i = 0; i < taille - 1 && src[i]; i++)
        dst[i] = (char)tolower((unsigned char)src[i]);
    dst[i] = '\0';
}

int recherche_par_terme(const Bibliotheque *b, const char *terme)
{
    char terme_low[100], titre_low[MAX_TITRE], auteur_low[MAX_AUTEUR];
    int  resultats = 0;

    to_lower(terme_low, terme, sizeof(terme_low));

    for (int i = 0; i < b->nb; i++) {
        to_lower(titre_low,  b->livres[i].titre,  sizeof(titre_low));
        to_lower(auteur_low, b->livres[i].auteur, sizeof(auteur_low));

        /* recherche partielle : le terme peut etre dans le titre ou l'auteur */
        if (strstr(titre_low, terme_low) || strstr(auteur_low, terme_low)) {
            printf("%d. %s — %s (%d) [%s]\n",
                i + 1,
                b->livres[i].titre,
                b->livres[i].auteur,
                b->livres[i].annee,
                b->livres[i].disponible ? "disponible" : "emprunte");
            resultats++;
        }
    }

    if (resultats == 0)
        printf("Aucun resultat pour \"%s\".\n", terme);
    else
        printf("%d resultat(s).\n", resultats);

    return resultats;
}

int recherche_changer_statut(Bibliotheque *b, int index)
{
    if (index < 0 || index >= b->nb)
        return 0;

    b->livres[index].disponible = !b->livres[index].disponible;

    printf("Statut mis a jour : %s est maintenant %s.\n",
        b->livres[index].titre,
        b->livres[index].disponible ? "disponible" : "emprunte");
    return 1;
}