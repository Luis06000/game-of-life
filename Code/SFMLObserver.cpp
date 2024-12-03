#include "SFMLObserver.h"

SFMLObserver::SFMLObserver(int cellSize)
    : cellSize(cellSize), gridWidth(0), gridHeight(0) {}

void SFMLObserver::initialize(const std::vector<std::vector<int>>& data) {
    if (data.empty() || data[0].empty()) return;
    
    gridHeight = data.size();
    gridWidth = data[0].size();
    
    // Create window with the correct size based on the grid dimensions
    window.create(
        sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize),
        "Game of Life",
        sf::Style::Titlebar | sf::Style::Close
    );
    window.setFramerateLimit(60);
}

void SFMLObserver::update(const std::vector<std::vector<int>>& data) {
    if (!window.isOpen()) {
        initialize(data);
    }

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

    // Handle window events
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

sf::RenderWindow& SFMLObserver::getWindow() {
    return window;
}

bool SFMLObserver::isWindowOpen() const {
    return window.isOpen();
}