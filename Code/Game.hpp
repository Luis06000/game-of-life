#ifndef GAME_H
#define GAME_H

#include "FileParser.hpp"
#include "Grid.hpp"

class Game {
private:
    FileParser fileParser;
    Grid grid;

public:
    void Create();
    void UpdateGrid();
};

#endif // GAME_H
