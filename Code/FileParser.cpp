#include "FileParser.hpp"
#include <iostream>
#include <fstream>

void FileParser::GetFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        // Lire le fichier et initialiser length et width
        file >> length >> width;
    } else {
        std::cerr << "Erreur d'ouverture du fichier." << std::endl;
    }
}
