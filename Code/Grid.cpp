#include "Grid.hpp"

void Grid::CreateGrid(int width, int height) {
    data.resize(height, std::vector<Cells>(width, Cells("")));
    // Initialisation des cellules
}
