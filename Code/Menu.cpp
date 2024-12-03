#include "Menu.h"
#include <iostream>
#include <limits>

Menu::Menu() : iterations(0), displayChoice(0) {
    std::cout << "Enter to start!\n"<<std::endl;
}

void Menu::ShowMenu() {
    // Effacer le buffer d'entree
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Demander le fichier
    std::cout << "=== Menu du Jeu de la Vie ===" << std::endl;
    std::cout << "Entrez le chemin du fichier texte (ex: grid.txt): ";
    std::getline(std::cin, filePath);

    // Demander les iterations
    while (true) {
        std::cout << "Entrez le nombre d'iterations (1-10000): ";
        if (std::cin >> iterations && iterations > 0 && iterations <= 10000) {
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
        std::cout << "2. Affichage avance" << std::endl;
        std::cout << "Entrez votre choix (1 ou 2): ";
        if (std::cin >> displayChoice && (displayChoice == 1 || displayChoice == 2)) {
            break;
        }
        std::cout << "Erreur: Veuillez entrer un choix valide (1 ou 2)." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Demander le délai entre les itérations
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
