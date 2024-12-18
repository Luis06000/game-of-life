#pragma once
#include <string>

class Menu {
private:
    std::string filePath;
    int iterations;
    int displayChoice;
    int delay;

public:
    Menu();
    void ShowMenu();
    std::string GetFilePath() const;
    int GetIterations() const;
    int GetDisplayChoice() const;
    int GetDelay() const;
};
