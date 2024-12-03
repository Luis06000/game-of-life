#include "FileVerify.h"
#include <iostream>

FileVerify::FileVerify() : SizeOk(false), ValuesOk(false) {}

void FileVerify::Verify(const std::vector<std::vector<int>>& data, int expectedLength, int expectedWidth) {
    // Vérifier la taille
    SizeOk = true; // On part du principe que c'est valide
    if (data.size() != static_cast<size_t>(expectedLength)) {
        std::cerr << "Erreur : Le nombre de lignes dans les données ne correspond pas à la longueur attendue.\n";
        SizeOk = false;
    }

    for (const auto& row : data) {
        if (row.size() != static_cast<size_t>(expectedWidth)) {
            std::cerr << "Erreur : La taille de la ligne ne correspond pas à la largeur attendue.\n";
            SizeOk = false;
            break;
        }
    }

    // Vérifier les valeurs (existant déjà)
    ValuesOk = true;
    for (const auto& row : data) {
        for (int cell : row) {
            if (cell != 0 && cell != 1) {
                std::cerr << "Erreur : Une valeur de cellule invalide a été trouvée dans les données. Seuls 0 et 1 sont autorisés.\n";
                ValuesOk = false;
                break;
            }
        }
        if (!ValuesOk) break;
    }
}

bool FileVerify::GetSizeOk() const {
    return SizeOk;
}

bool FileVerify::GetValuesOk() const {
    return ValuesOk;
}

