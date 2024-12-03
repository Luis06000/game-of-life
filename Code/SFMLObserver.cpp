#include "SFMLObserver.h"

SFMLObserver::SFMLObserver(int gridSize, int cellSize)
    : cellSize(cellSize),
      window(sf::VideoMode(gridSize * cellSize, gridSize * cellSize), "Game of Life") {}

void SFMLObserver::update(const std::vector<std::vector<int>>& data) {
    window.clear(sf::Color::Black);
    for (size_t y = 0; y < data.size(); ++y) {
        for (size_t x = 0; x < data[y].size(); ++x) {
            if (data[y][x]) {
                sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
                cell.setPosition(x * cellSize, y * cellSize);
                cell.setFillColor(sf::Color::White);
                window.draw(cell);
            }
        }
    }
    window.display();
}

sf::RenderWindow& SFMLObserver::getWindow() {
    return window;
}
