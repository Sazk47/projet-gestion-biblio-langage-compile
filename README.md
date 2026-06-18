# Bibliothèque — Application console (C)

Gestion de livres avec CRUD et sauvegarde fichier. Projet final — Découverte des langages compilés.

## Compilation & exécution

```bash
make        # compile -> bin/bibliotheque
make run    # compile et lance
make clean  # supprime build/ et bin/
```

## Structure

```
include/   en-têtes (.h)
src/       sources (.c)
build/     objets (.o) générés
bin/       exécutable généré
data/      bibliotheque.txt (sauvegarde)
```

## Répartition

| Module          | Fichiers                        | Responsable |
|-----------------|---------------------------------|-------------|
| Struct partagée | `livre.h`                       | A + B       |
| Catalogue (CRUD)| `catalogue.h/.c`, `main.c`      | A           |
| Recherche       | `recherche.h/.c`                | B           |
| Persistance     | `persistance.h/.c`              | B           |
| UI / saisies    | `ui.h/.c`                       | B           |

## Format de sauvegarde

Un livre par ligne : `titre;auteur;annee;disponible` (disponible = 0 ou 1).
