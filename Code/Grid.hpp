#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Cells.hpp"

class Grid {
private:
    std::vector<std::vector<Cells>> data;

public:
    void CreateGrid(int width, int height);
    std::vector<std::vector<Cells>> GetData() const { return data; }
};

#endif // GRID_H
