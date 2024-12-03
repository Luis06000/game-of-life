#include "Game.h"
#include "ConsoleObserver.h"
#include "SFMLObserver.h"

int main() {
    Game game("grid.txt", 35);
    
    auto consoleObserver = new ConsoleObserver();
    auto sfmlObserver = new SFMLObserver(50);  // Adjust size based on your grid
    
    game.attach(consoleObserver);
    game.attach(sfmlObserver);
    
    game.Run();
    
    delete consoleObserver;
    delete sfmlObserver;
    
    return 0;
}