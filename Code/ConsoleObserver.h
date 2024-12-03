#pragma once

#include "Observer.h"
#include <iostream>

class ConsoleObserver : public Observer {
public:
    void update(const std::vector<std::vector<int>>& data) override;
};
