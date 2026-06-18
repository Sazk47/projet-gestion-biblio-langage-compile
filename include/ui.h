#ifndef UI_H
#define UI_H

/* Module UI — Personne B
 * Affichage du menu + saisies console sécurisées.
 * Interface proposée par A, ajustable par B. */

/* Affiche le menu principal. */
void ui_afficher_menu(void);

/* Lit un entier au clavier avec validation. */
int ui_lire_entier(const char *invite);

/* Lit une chaîne (max `taille` caractères, '\n' retiré). */
void ui_lire_chaine(const char *invite, char *dest, int taille);

#endif /* UI_H */
