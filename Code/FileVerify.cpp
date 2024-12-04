#include "FileVerify.h"
#include <iostream>

FileVerify::FileVerify() : SizeOk(false), ValuesOk(false) {}

void FileVerify::Verify(const std::vector<std::vector<int>>& data, int expectedLength, int expectedWidth) {
    // Vérifier la taille
    SizeOk = true;
    if (data.size() != static_cast<size_t>(expectedLength)) {
        std::cerr << "Erreur : Le nombre de lignes dans les donnees ne correspond pas à la longueur attendue.\n";
        SizeOk = false;
    }

    for (const auto& row : data) {
        if (row.size() != static_cast<size_t>(expectedWidth)) {
            std::cerr << "Erreur : La taille de la ligne ne correspond pas à la largeur attendue.\n";
            SizeOk = false;
            break;
        }
    }

    // Vérifier les valeurs (0,1,2,3 sont maintenant valides)
    ValuesOk = true;
    for (const auto& row : data) {
        for (int cell : row) {
            if (cell < 0 || cell > 3) {
                std::cerr << "Erreur : Une valeur de cellule invalide a ete trouvee dans les donnees. Seuls 0, 1, 2 et 3 sont autorises.\n";
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

