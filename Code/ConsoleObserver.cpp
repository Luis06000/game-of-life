#include "ConsoleObserver.h"

void ConsoleObserver::update(const std::vector<std::vector<int>>& data) {
    for (const auto& row : data) {
        for (int cell : row) {
            std::cout << (cell ? "1" : "0") << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::string(20, '-') << std::endl; // Separator
}
