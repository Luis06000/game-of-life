#include "Game.h"
#include "ConsoleObserver.h"
#include "SFMLObserver.h"
#include "FileObserver.h"
#include "Menu.h"

int main() {
    Menu menu;
    menu.ShowMenu();

    Game game(menu.GetFilePath(), menu.GetIterations(), menu.GetDelay());
    
    // Create and attach the FileObserver
    FileObserver* fileObserver = new FileObserver();
    game.attach(fileObserver);
    
    // Create and attach the display observer based on user choice
    Observer* displayObserver = nullptr;
    if (menu.GetDisplayChoice() == 1) {
        displayObserver = new ConsoleObserver();
    } else {
        displayObserver = new SFMLObserver(50);
    }
    game.attach(displayObserver);
    
    game.Run();
    
    // Clean up
    delete fileObserver;
    delete displayObserver;
    
    return 0;
}