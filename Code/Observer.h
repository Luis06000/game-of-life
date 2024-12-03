#pragma once

#include <vector>

class Observer {
public:
    virtual void update(const std::vector<std::vector<int>>& data) = 0;
    virtual ~Observer() = default;
};

