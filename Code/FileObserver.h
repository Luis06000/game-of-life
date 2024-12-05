#pragma once

#include "Observer.h"
#include <fstream>
#include <string>
#include <iostream>

class FileObserver : public Observer {
private:
    std::ofstream file;
    int currentIteration;
    const int MAX_ITERATIONS = 50;
    bool fileOpenSuccessful;

public:
    FileObserver(const std::string& inputFilename) : currentIteration(0) {
        std::string outputFilename;
        size_t lastDot = inputFilename.find_last_of(".");
        if (lastDot != std::string::npos) {
            outputFilename = inputFilename.substr(0, lastDot) + "_out" + inputFilename.substr(lastDot);
        } else {
            outputFilename = inputFilename + "_out";
        }

        file.open(outputFilename);
        fileOpenSuccessful = file.is_open();
        if (!fileOpenSuccessful) {
            std::cerr << "Erreur : Impossible de créer ou d'ouvrir le fichier : " << outputFilename << std::endl;
        }
    }

    ~FileObserver() {
        if (file.is_open()) {
            file.close();
        }
    }

    void update(const std::vector<std::vector<int>>& data) override {
        if (!fileOpenSuccessful || currentIteration >= MAX_ITERATIONS) return;
        
        file << "Iteration " << currentIteration << ":\n";
        for (const auto& row : data) {
            for (int cell : row) {
                file << (cell ? "1" : "0") << " ";
            }
            file << "\n";
        }
        file << "\n";
        currentIteration++;
        
        // Forcer l'écriture immédiate dans le fichier
        file.flush();
    }
};