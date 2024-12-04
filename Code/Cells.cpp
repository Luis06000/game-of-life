#include "Cells.h"

Cells::State Cells::GetState() const {
    return state;
}

void Cells::SetState(State newState) {
    state = newState;
}

std::string Cells::GetPosition() const {
    return position;
}
