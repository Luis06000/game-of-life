#include "Game.h"
#include "ConsoleObserver.h"
#include "SFMLObserver.h"
#include "Menu.h"

int main() {
    Menu menu;
    menu.ShowMenu();

    Game game(menu.GetFilePath(), menu.GetIterations());
    
    Observer* observer = nullptr;
    
    if (menu.GetDisplayChoice() == 1) {
        observer = new ConsoleObserver();
    } else {
        observer = new SFMLObserver(50);
    }
    
    game.attach(observer);
    game.Run();
    
    delete observer;
    
    return 0;
}