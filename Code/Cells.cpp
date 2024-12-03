#include "Cells.h"

bool Cells::GetState() const {
    return state;
}

void Cells::SetState(bool newState) {
    state = newState;
}

std::string Cells::GetPosition() const {
    return position;
}
