#include "GridVerify.h"

void GridVerify::CheckStatic(const std::vector<std::vector<int>>& currentState, const std::vector<std::vector<int>>& previousState) {
    isStatic = (currentState == previousState);
}

bool GridVerify::GetIsStatic() const {
    return isStatic;
}

bool GridVerify::GetIsEmpty() const {
    return isEmpty;
}

bool GridVerify::GetRepeat() const {
    return Repeat;
}

void GridVerify::CheckRepeat(const std::vector<std::vector<int>>& currentState, const std::vector<std::vector<int>>& twoIterationsAgoState) {
    Repeat = (currentState == twoIterationsAgoState);
}
