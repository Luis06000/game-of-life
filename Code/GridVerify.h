#pragma once
#include <vector>

class GridVerify {
private:
    bool isEmpty;
    bool Repeat;
    bool isStatic;

public:
    GridVerify() : isEmpty(false), Repeat(false), isStatic(false) {}
    bool GetIsEmpty() const;
    bool GetRepeat() const;
    bool GetIsStatic() const;
    void CheckStatic(const std::vector<std::vector<int>>& currentState, const std::vector<std::vector<int>>& previousState);
    void CheckRepeat(const std::vector<std::vector<int>>& currentState, const std::vector<std::vector<int>>& twoIterationsAgoState);
};

