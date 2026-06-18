# GESTION DE BIBLIOTHÈQUE

Application de gestion de livres en C avec CRUD (Créer, Lire, Modifier, Supprimer). Gérez vos livres, recherchez par titre ou auteur, et empruntez/rendez vos acquisitions.

## Sommaire

- [Installation](#installation)
- [Fonctionnalités Détaillées](#fonctionnalités-détaillées)
  - [Gestion des Livres](#gestion-des-livres)
  - [Recherche & Emprunt](#recherche--emprunt)
  - [Sauvegarde](#sauvegarde)
- [Particularités Techniques](#particularités-techniques)
  - [Architecture Modulaire](#architecture-modulaire)
  - [Structures de Données](#structures-de-données)
- [Commandes](#commandes)
- [Architecture](#architecture)
- [Compilation & Exécution](#compilation--exécution)

## Installation

**Prérequis** : GCC (ou clang), Make, C99

```bash
git clone https://github.com/Sazk47/projet-gestion-biblio-langage-compile.git
cd projet-gestion-biblio-langage-compile
make
```

## Fonctionnalités Détaillées

### Gestion des Livres

- **Ajouter un livre** : titre, auteur, année de publication (1000-2100)
- **Afficher tous les livres** : liste complète avec statut (disponible/emprunté)
- **Supprimer un livre** : avec confirmation avant suppression
- **Validation des données** :
  - Titre et auteur obligatoires (non vides)
  - Année entre 1000 et 2100
  - Détection automatique des doublons (même titre + auteur)

### Recherche & Emprunt

| Fonctionnalité | Description |
|---|---|
| **Recherche** | Partielle, insensible à la casse (titre ou auteur) |
| **Emprunter** | Change le statut d'un livre en "emprunté" |
| **Rendre** | Restaure le statut "disponible" d'un livre |

### Sauvegarde

- **Format** : Fichier texte délimité par `;`
- **Données stockées** : titre, auteur, année, disponibilité
- **Chargement automatique** : au démarrage (si `data/bibliotheque.txt` existe)
- **Sauvegarde manuelle** : avant de quitter l'application

**Format du fichier** :
```
1984;George Orwell;1949;0
Le Seigneur des Anneaux;J.R.R. Tolkien;1954;1
```

## Particularités Techniques

### Architecture Modulaire

| Module | Responsabilité |
|--------|---|
| **livre.h** | Structure de données `Livre` (partagée) |
| **catalogue.c** | CRUD : ajouter, afficher, supprimer |
| **recherche.c** | Recherche et gestion du statut (emprunter/rendre) |
| **persistance.c** | Sauvegarde/chargement fichier CSV |
| **ui.c** | Menu et saisies utilisateur |
| **main.c** | Boucle de jeu et orchestration |

### Structures de Données

| Structure | Usage |
|---|---|
| `Livre` | Titre, auteur, année, disponibilité |
| `Bibliotheque` | Tableau dynamique de livres (`Livre *`) |
| Tableau dynamique | Gestion flexible du nombre de livres |

## Commandes

| Menu | Description |
|---|---|
| **1. Ajouter un livre** | Saisir titre, auteur, année |
| **2. Afficher tous les livres** | Liste complète numérotée |
| **3. Rechercher** | Par titre ou auteur (partielle) |
| **4. Emprunter / Rendre** | Basculer le statut disponible/emprunté |
| **5. Supprimer un livre** | Avec confirmation |
| **6. Sauvegarder et quitter** | Enregistre et ferme l'application |

## Architecture

```
projet-gestion-biblio-langage-compile/
├── Makefile                 # Configuration de compilation
├── README.md               # Ce fichier
├── include/
│   ├── livre.h             # Structure Livre (partagé A+B)
│   ├── catalogue.h         # Ajouter, afficher, supprimer
│   ├── recherche.h         # Rechercher, emprunter, rendre
│   ├── persistance.h       # Save/load CSV
│   └── ui.h                # Menus + saisies console
├── src/
│   ├── main.c              # Point d'entrée + boucle de jeu
│   ├── catalogue.c         # Logique CRUD de base
│   ├── recherche.c         # Recherche + gestion statut
│   ├── persistance.c       # Sauvegarde/chargement
│   └── ui.c                # Menu + entrées utilisateur
├── build/                  # Fichiers objets (.o)
├── bin/                    # Exécutable (bibliotheque)
└── data/
    └── bibliotheque.txt    # Base de données persistante
```

## Compilation & Exécution

### Compiler
```bash
make
```

### Exécuter
```bash
make run
```
ou directement :
```bash
./bin/projet-gestion-biblio-langage-compile
```

### Nettoyer les fichiers compilés
```bash
make clean
```

## Exemple d'Utilisation

```
=== BIBLIOTHÈQUE ===
1. Ajouter un livre
2. Afficher tous les livres
3. Rechercher
4. Emprunter / Rendre
5. Supprimer un livre
6. Sauvegarder et quitter
Votre choix : 1

Titre   : 1984
Auteur  : George Orwell
Annee   : 1949
Livre ajouté avec succès.

=== BIBLIOTHÈQUE ===
...
Votre choix : 3

Entrez un titre ou auteur : 1984
1. 1984 - George Orwell (1949) [disponible]
1 résultat(s).
```
