#include "Game.h"
#include <iostream>
#include <thread>
#include <chrono>

Game::Game(const std::string& filePath, int iterations, int delay) 
    : file(filePath), nbIteration(iterations), delay(delay) {}

void Game::PrintData() {
    notify();
}

void Game::GetFile() {
    FileParser parser(file);
    FileVerify verifier;
    verifier.Verify(parser.GetData(), parser.GetLength(), parser.GetWidth());
// essayer appeler verify par parser

    if (!verifier.GetSizeOk() || !verifier.GetValuesOk()) {
        std::cerr << "Error: Invalid file data\n";
        return;
    }

    grid.CreateGrid(parser.GetData());
    currentState = grid.GetData();
    setData(currentState);
}

int Game::CountNeighbors(int row, int col) {
    int count = 0;
    int rows = currentState.size();
    int cols = currentState[0].size();
    
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            
            int newRow = (row + i + rows) % rows;    // Wrap around edges
            int newCol = (col + j + cols) % cols;    // Wrap around edges
            
            count += currentState[newRow][newCol];
        }
    }
    return count;
}

void Game::UpdateGrid() {
    std::vector<std::vector<int>> newState = currentState;
    int rows = currentState.size();
    int cols = currentState[0].size();
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = CountNeighbors(i, j);
            
            if (currentState[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    newState[i][j] = 0;
                }
            } else {
                if (neighbors == 3) {
                    newState[i][j] = 1;
                }
            }
        }
    }
    
    currentState = newState;
    setData(currentState);
}


void Game::Run() {
    GetFile();
    
    for (int i = 0; i < nbIteration; i++) {
        PrintData();  // Affiche la grille au début de chaque itération
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        UpdateGrid();
    }
    
    End();
}

void Game::End() {
    std::cout << "Game finished after " << nbIteration << " iterations.\n";
}