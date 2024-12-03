#include "Grid.h"

void Grid::CreateGrid(const std::vector<std::vector<int>>& inputData) {
    data = inputData;
}

const std::vector<std::vector<int>>& Grid::GetData() const {
    return data;
}
