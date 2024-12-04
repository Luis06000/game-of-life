#pragma once

#include "Observer.h"
#include <fstream>
#include <string>
#include <iostream>

class FileObserver : public Observer {
private:
    std::ofstream file;
    int currentIteration;
    const int MAX_ITERATIONS = 5;
    bool fileOpenSuccessful;

public:
    FileObserver(const std::string& filename = "game_iterations.txt") : currentIteration(0) {
        file.open(filename);
        fileOpenSuccessful = file.is_open();
        if (!fileOpenSuccessful) {
            std::cerr << "Error: Could not create or open file: " << filename << std::endl;
        }
    }

    ~FileObserver() {
        if (file.is_open()) {
            file.close();
        }
    }

    void update(const std::vector<std::vector<int>>& data) override {
        if (!fileOpenSuccessful) return;
        
        if (currentIteration < MAX_ITERATIONS && file.is_open()) {
            file << "Iteration " << currentIteration << ":\n";
            for (const auto& row : data) {
                for (int cell : row) {
                    file << (cell ? "1" : "0") << " ";
                }
                file << "\n";
            }
            file << "\n";
            currentIteration++;
        }
    }
};