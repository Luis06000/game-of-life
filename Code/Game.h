#pragma once

#include "FileParser.h"
#include "FileVerify.h"
#include "Grid.h"
#include "GridVerify.h"
#include "ConcreteSubject.h"
#include "Observer.h"

class Game : public ConcreteSubject {
private:
    std::string file;
    Grid grid;
    int nbIteration;
    int delay;
    std::vector<std::vector<int>> currentState;

public:
    Game(const std::string& filePath, int iterations, int delay);
    void PrintData();
    void GetFile();
    void UpdateGrid();
    void ValidateGrid();
    void End();
    void Run();
    int CountNeighbors(int row, int col);
};