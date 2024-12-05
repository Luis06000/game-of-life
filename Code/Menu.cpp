#include "Menu.h"
#include <iostream>
#include <limits>

Menu::Menu() : iterations(0), displayChoice(0) {
    std::cout << "Pressez 'entrer' pour commencer\n"<<std::endl;
}

void Menu::ShowMenu() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "=== Menu du Jeu de la Vie ===" << std::endl;
    std::cout << "Entrez le chemin du fichier texte (ex: ./Grids/grid.txt): ";
    std::getline(std::cin, filePath);

    while (true) {
        std::cout << "Entrez le nombre d'iterations (1-10000): ";
        if (std::cin >> iterations && iterations > 0 && iterations <= 10000) {
            break;
        }
        std::cout << "Erreur: Veuillez entrer un nombre valide entre 1 et 10000." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        std::cout << "Choisissez le type d'affichage:" << std::endl;
        std::cout << "1. Affichage console" << std::endl;
        std::cout << "2. Affichage graphique" << std::endl;
        std::cout << "3. Affichage graphique avec enregistrement" << std::endl;
        std::cout << "Entrez votre choix (1, 2 ou 3): ";
        if (std::cin >> displayChoice && (displayChoice == 1 || displayChoice == 2 || displayChoice == 3)) {
            break;
        }
        std::cout << "Erreur: Veuillez entrer un choix valide (1, 2 ou 3)." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        std::cout << "Entrez le delai entre les iterations (en millisecondes): ";
        if (std::cin >> delay && delay >= 0) {
            break;
        }
        std::cout << "Erreur: Veuillez entrer un nombre valide." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string Menu::GetFilePath() const {
    return filePath;
}

int Menu::GetIterations() const {
    return iterations;
}

int Menu::GetDisplayChoice() const {
    return displayChoice;
}

int Menu::GetDelay() const {
    return delay;
}
