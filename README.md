# Projet : Jeu de la Vie

## Description
Ce projet implémente le célèbre "Jeu de la Vie" de John Conway, un automate cellulaire qui simule l'évolution d'une population de cellules sur une grille. Les cellules peuvent être vivantes ou mortes, et leur état évolue selon des règles simples basées sur le nombre de voisins vivants.

## Fonctionnalités
- **Création de la grille** : Génération d'une grille de cellules avec des dimensions spécifiées.
- **Lecture de fichiers** : Chargement des dimensions de la grille à partir d'un fichier de configuration.
- **Mise à jour des cellules** : Application des règles du jeu pour mettre à jour l'état des cellules à chaque itération.

## Installation
Pour exécuter ce projet, assurez-vous d'avoir un compilateur C++ installé (comme g++) et suivez ces étapes :

1. Clonez le dépôt :
   ```bash
   git clone https://github.com/Luis06000/game-of-life.git
   cd game-of-life
   ```

2. Compilez le projet :
   ```bash
   g++ -o game_of_life main.cpp Game.cpp FileParser.cpp Grid.cpp Cells.cpp
   ```

3. Exécutez le programme :
   ```bash
   ./game_of_life
   ```

## Utilisation
- Créez un fichier de configuration (par exemple, `data.txt`) contenant les dimensions de la grille (longueur et largeur).
- Lancez le programme pour voir l'évolution des cellules sur la grille.

## Auteurs
- [Fernandes Luis](https://github.com/Luis06000)
- [Krichko Egor](https://github.com/maratPVE)
- [Braun Julien](https://github.com/Silverxs83)
