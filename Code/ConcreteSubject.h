#pragma once

#include "Subject.h"
#include <vector>
#include <algorithm>

class ConcreteSubject : public Subject {
private:
    std::vector<Observer*> observers;
    std::vector<std::vector<int>> data;

public:
    void setData(const std::vector<std::vector<int>>& newData);
    std::vector<std::vector<int>> getData() const;

    void attach(Observer* observer) override;
    void detach(Observer* observer) override;
    void notify() override;
};
