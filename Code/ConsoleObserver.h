#ifndef CONSOLEOBSERVER_H
#define CONSOLEOBSERVER_H

#include "Observer.h"
#include <iostream>

class ConsoleObserver : public Observer {
public:
    void update(const std::vector<std::vector<int>>& data) override;
};

#endif // CONSOLEOBSERVER_H
