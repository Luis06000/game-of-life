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
    std::vector<std::vector<int>> twoIterationsAgoState;
    bool isStatic;
    bool isEmpty;
    bool repeat;

public:
    Game(const std::string& filePath, int iterations, int delay);
    Game(const std::vector<std::vector<int>>& initialGrid, int iterations = 1, int delay = 0);
    void PrintData();
    void GetFile();
    void UpdateGrid();
    void ValidateGrid();
    void End();
    void Run();
    int CountNeighbors(int row, int col);
    Grid& GetGrid() { return grid; }
    const std::vector<std::vector<int>>& GetCurrentState() const { return currentState; }
};