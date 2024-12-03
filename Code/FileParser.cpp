#include "FileParser.h"
#include <fstream>
#include <sstream>
#include <iostream>

FileParser::FileParser(const std::string& filePath) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filePath << "\n";
        length = 0;
        width = 0;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream stream(line);
        int cell;

        while (stream >> cell) {
            row.push_back(cell);
        }

        if (data.empty()) {
            width = row.size();
        } else if (row.size() != static_cast<size_t>(width)) {
            std::cerr << "Erreur : Les tailles des lignes dans le fichier sont incoherentes.\n";
            data.clear();
            length = 0;
            width = 0;
            return;
        }

        data.push_back(row);
    }

    length = data.size();
    file.close();
}

int FileParser::GetLength() const {
    return length;
}

int FileParser::GetWidth() const {
    return width;
}

const std::vector<std::vector<int>>& FileParser::GetData() const {
    return data;
}

