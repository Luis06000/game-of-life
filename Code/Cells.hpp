#ifndef CELLS_H
#define CELLS_H

#include <string>

class Cells {
private:
    bool state;
    std::string position;

public:
    Cells(std::string pos) : position(pos), state(false) {}
    bool GetState() const { return state; }
    void SetState(bool newState) { state = newState; }
    std::string GetPosition() const { return position; }
};

#endif // CELLS_H
