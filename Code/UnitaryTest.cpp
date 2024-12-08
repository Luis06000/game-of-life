#include <cassert>
#include <iostream>
#include "Game.h"

class UnitaryTest {
public:
    static void runAllTests() {
        testBlinker();
        std::cout << "Tous les tests ont ete executes avec succes!" << std::endl;
    }

    static void testBlinker() {
        std::cout << "Test du blinker..." << std::endl;

        std::vector<std::vector<int>> initialState = {
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        };
        std::cout << "Etat initial cree" << std::endl;

        std::vector<std::vector<int>> expectedState = {
            {0, 0, 0, 0},
            {0, 1, 1, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };
        std::cout << "Etat attendu cree" << std::endl;

        std::cout << "Creation de l'instance Game..." << std::endl;
        Game game(initialState);
        std::cout << "Instance Game creee" << std::endl;

        std::cout << "Mise a jour de la grille..." << std::endl;
        game.UpdateGrid();
        std::cout << "Grille mise a jour" << std::endl;

        std::cout << "Verification des resultats..." << std::endl;
        const auto& resultState = game.GetCurrentState();
        bool testPassed = compareGrids(resultState, expectedState);

        if (testPassed) {
            std::cout << "Test du blinker reussi!" << std::endl;
        } else {
            std::cout << "Test du blinker echoue!" << std::endl;
            std::cout << "Etat obtenu:" << std::endl;
            printGrid(resultState);
            std::cout << "Etat attendu:" << std::endl;
            printGrid(expectedState);
        }

        assert(testPassed && "Le test du blinker a echoue");
    }

private:
    static bool compareGrids(const std::vector<std::vector<int>>& grid1, 
                           const std::vector<std::vector<int>>& grid2) {
        if (grid1.empty() || grid2.empty() || 
            grid1.size() != grid2.size() || 
            grid1[0].size() != grid2[0].size()) {
            return false;
        }

        for (size_t i = 0; i < grid1.size(); i++) {
            for (size_t j = 0; j < grid1[0].size(); j++) {
                if (grid1[i][j] != grid2[i][j]) return false;
            }
        }
        return true;
    }

    static void printGrid(const std::vector<std::vector<int>>& grid) {
        for (const auto& row : grid) {
            for (int cell : row) {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    UnitaryTest::runAllTests();
    return 0;
}
