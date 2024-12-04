#pragma once

#include <string>

class Cells {
public:
    enum State {
        DEAD = 0,
        ALIVE = 1
    };

protected:
    State state;
    std::string position;

public:
    Cells() : state(DEAD) {}
    virtual ~Cells() = default;
    
    virtual State GetState() const;
    virtual void SetState(State newState);
    std::string GetPosition() const;
};

