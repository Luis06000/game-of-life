#include "Menu.h"
#include <iostream>
#include <limits>

Menu::Menu() : iterations(0), displayChoice(0) {}

void Menu::ShowMenu() {
    // Effacer le buffer d'entrée
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Demander le fichier
    std::cout << "=== Menu du Jeu de la Vie ===" << std::endl;
    std::cout << "Entrez le chemin du fichier texte (ex: grid.txt): ";
    std::getline(std::cin, filePath);

    // Demander les itérations
    while (true) {
        std::cout << "Entrez le nombre d'itérations (1-1000): ";
        if (std::cin >> iterations && iterations > 0 && iterations <= 1000) {
            break;
        }
        std::cout << "Erreur: Veuillez entrer un nombre valide entre 1 et 1000." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Demander le type d'affichage
    while (true) {
        std::cout << "Choisissez le type d'affichage:" << std::endl;
        std::cout << "1. Affichage simple" << std::endl;
        std::cout << "2. Affichage avancé" << std::endl;
        std::cout << "Entrez votre choix (1 ou 2): ";
        if (std::cin >> displayChoice && (displayChoice == 1 || displayChoice == 2)) {
            break;
        }
        std::cout << "Erreur: Veuillez entrer un choix valide (1 ou 2)." << std::endl;
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
