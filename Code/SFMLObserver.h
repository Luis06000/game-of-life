#ifndef SFML_OBSERVER_H
#define SFML_OBSERVER_H

#include "Observer.h"
#include <SFML/Graphics.hpp>

class SFMLObserver : public Observer {
private:
    int cellSize;
    sf::RenderWindow window;

public:
    SFMLObserver(int gridSize, int cellSize = 20);
    void update(const std::vector<std::vector<int>>& data) override;

    sf::RenderWindow& getWindow();
};

#endif // SFML_OBSERVER_H
