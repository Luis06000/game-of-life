// #ifndef FILEVERIFY_H
// #define FILEVERIFY_H

// #include <vector>

// class FileVerify {
// private:
//     bool sizeOk;
//     bool valuesOk;

// public:
//     FileVerify(int length, int width, const std::vector<std::vector<int>>& data);
//     bool GetSizeOk() const;
//     bool GetValuesOk() const;
// };

// #endif // FILEVERIFY_H

#ifndef FILEVERIFY_H
#define FILEVERIFY_H

#include <vector>

class FileVerify {
private:
    bool SizeOk;    // Indique si la taille de la grille est correcte
    bool ValuesOk;  // Indique si les valeurs dans la grille sont valides (0 ou 1)

public:
    FileVerify();  // Constructeur par défaut

    /**
     * Vérifie la validité des données de la grille.
     * @param data Les données de la grille.
     * @param expectedLength Le nombre attendu de lignes.
     * @param expectedWidth Le nombre attendu de colonnes.
     */
    void Verify(const std::vector<std::vector<int>>& data, int expectedLength, int expectedWidth);

    /**
     * Retourne si la taille de la grille est correcte.
     * @return true si la taille est valide, false sinon.
     */
    bool GetSizeOk() const;

    /**
     * Retourne si les valeurs dans la grille sont valides.
     * @return true si les valeurs sont valides (0 ou 1), false sinon.
     */
    bool GetValuesOk() const;
};

#endif // FILEVERIFY_H
