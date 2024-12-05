#include "Game.h"
#include <iostream>
#include <thread>
#include <chrono>

Game::Game(const std::string& filePath, int iterations, int delay) 
    : file(filePath), nbIteration(iterations), delay(delay), 
      isStatic(false), isEmpty(false), repeat(false) {
    twoIterationsAgoState = std::vector<std::vector<int>>();
}

Game::Game(const std::vector<std::vector<int>>& initialGrid, int iterations, int delay)
    : nbIteration(iterations), delay(delay), 
      isStatic(false), isEmpty(false), repeat(false) {
    currentState = initialGrid;
    twoIterationsAgoState = initialGrid;
    grid.CreateGrid(initialGrid);
    setData(currentState);
}

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
            
            int newRow = (row + i + rows) % rows;
            int newCol = (col + j + cols) % cols;
            
            if (currentState[newRow][newCol] == 1 || currentState[newRow][newCol] == 3) {
                count++;
            }
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
            if (currentState[i][j] >= 2) {
                continue;
            }
            
            int neighbors = CountNeighbors(i, j);
            
            if (currentState[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    newState[i][j] = 0;
                }
            } else if (currentState[i][j] == 0) {
                if (neighbors == 3) {
                    newState[i][j] = 1;
                }
            }
        }
    }
    
    GridVerify verifier;
    verifier.CheckStatic(newState, currentState);
    verifier.CheckRepeat(newState, twoIterationsAgoState);
    isStatic = verifier.GetIsStatic();
    isEmpty = std::all_of(newState.begin(), newState.end(), [](const std::vector<int>& row) {
        return std::all_of(row.begin(), row.end(), [](int cell) { return cell == 0; });
    });
    repeat = verifier.GetRepeat();

    if (isStatic || isEmpty || repeat) {
        currentState = newState;
        setData(currentState);
        PrintData();
        End();
        exit(0);
    }
    
    twoIterationsAgoState = currentState;
    currentState = newState;
    setData(currentState);
}


void Game::Run() {
    GetFile();
    
    for (int i = 0; i < nbIteration; i++) {
        PrintData();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        UpdateGrid();
    }
    
    End();
}

void Game::End() {
    if (isStatic) {
        std::cout << "Le jeu s'arrete, la grille est statique.\n";
    } else if (isEmpty) {
        std::cout << "Le jeu s'arrete, la grille est vide.\n";
    } else if (repeat) {
        std::cout << "La grille n'evolue plus.\n";
    } else {
        std::cout << "Le jeu s'arrete apres " << nbIteration << " iterations.\n";
    }
}
