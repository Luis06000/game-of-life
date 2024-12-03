#ifndef SFML_OBSERVER_H
#define SFML_OBSERVER_H

#include "Observer.h"
#include <SFML/Graphics.hpp>

class SFMLObserver : public Observer {
private:
    int cellSize;
    sf::RenderWindow window;
    int gridWidth;
    int gridHeight;

public:
    SFMLObserver(int cellSize = 20);
    void update(const std::vector<std::vector<int>>& data) override;
    void initialize(const std::vector<std::vector<int>>& data);
    sf::RenderWindow& getWindow();
    bool isWindowOpen() const;
};

#endif // SFML_OBSERVER_H