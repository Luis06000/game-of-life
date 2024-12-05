#include "Game.h"
#include "ConsoleObserver.h"
#include "SFMLObserver.h"
#include "FileObserver.h"
#include "Menu.h"

int main() {
    Menu menu;
    menu.ShowMenu();

    Game game(menu.GetFilePath(), menu.GetIterations(), menu.GetDelay());
    
    if (menu.GetDisplayChoice() == 1 || menu.GetDisplayChoice() == 3) {
        FileObserver* fileObserver = new FileObserver(menu.GetFilePath());
        game.attach(fileObserver);
    }
    
    Observer* displayObserver = nullptr;
    if (menu.GetDisplayChoice() == 1) {
        displayObserver = new ConsoleObserver();
    } else {
        displayObserver = new SFMLObserver(50);
    }
    game.attach(displayObserver);
    
    game.Run();
    
    delete displayObserver;
    
    return 0;
}