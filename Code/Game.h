#ifndef GAME_H
#define GAME_H

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
    std::vector<std::vector<int>> currentState;

public:
    Game(const std::string& filePath, int iterations);
    void PrintData();
    void GetFile();
    void UpdateGrid();
    void ValidateGrid();
    void End();
    void Run();
    int CountNeighbors(int row, int col);
};

#endif // GAME_H