#include "Game.h"
#include "ConsoleObserver.h"
#include "SFMLObserver.h"

int main() {
    Game game("grid.txt", 35);
    
    auto consoleObserver = new ConsoleObserver();
    int desiredWindowSize = 800; // or whatever size you want
    int gridSize = 10; // your grid size
    int cellSize = desiredWindowSize / gridSize;
    
    auto sfmlObserver = new SFMLObserver(cellSize);
    game.attach(consoleObserver);
    game.attach(sfmlObserver);
    
    game.Run();
    
    delete consoleObserver;
    delete sfmlObserver;
    
    return 0;
}