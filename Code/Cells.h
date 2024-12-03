#ifndef CELLS_H
#define CELLS_H

#include <string>

class Cells {
private:
    bool state;
    std::string position;

public:
    bool GetState() const;
    void SetState(bool newState);
    std::string GetPosition() const;
};

#endif // CELLS_H
