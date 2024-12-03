// #include "FileVerify.h"

// FileVerify::FileVerify(int length, int width, const std::vector<std::vector<int>>& data) {
//     sizeOk = (length > 0 && width > 0);
//     valuesOk = true;

//     for (const auto& row : data) {
//         for (int cell : row) {
//             if (cell != 0 && cell != 1) {
//                 valuesOk = false;
//                 break;
//             }
//         }
//         if (!valuesOk) {
//             break;
//         }
//     }
// }

// bool FileVerify::GetSizeOk() const {
//     return sizeOk;
// }

// bool FileVerify::GetValuesOk() const {
//     return valuesOk;
// }

#include "FileVerify.h"
#include <iostream>

FileVerify::FileVerify() : SizeOk(false), ValuesOk(false) {}

void FileVerify::Verify(const std::vector<std::vector<int>>& data, int expectedLength, int expectedWidth) {
    // Vérifier la taille
    SizeOk = true; // On part du principe que c'est valide
    if (data.size() != static_cast<size_t>(expectedLength)) {
        std::cerr << "Error: Number of rows in the data does not match the expected length.\n";
        SizeOk = false;
    }

    for (const auto& row : data) {
        if (row.size() != static_cast<size_t>(expectedWidth)) {
            std::cerr << "Error: Row size does not match the expected width.\n";
            SizeOk = false;
            break;
        }
    }

    // Vérifier les valeurs (existant déjà)
    ValuesOk = true;
    for (const auto& row : data) {
        for (int cell : row) {
            if (cell != 0 && cell != 1) {
                std::cerr << "Error: Invalid cell value found in the data. Only 0 and 1 are allowed.\n";
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

