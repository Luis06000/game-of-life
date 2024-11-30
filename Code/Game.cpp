#include "Game.hpp"

void Game::Create() {
    fileParser.GetFile("data.txt");
    grid.CreateGrid(fileParser.GetWidth(), fileParser.GetLength());
}

void Game::UpdateGrid() {
    // Logique pour mettre à jour la grille
}
