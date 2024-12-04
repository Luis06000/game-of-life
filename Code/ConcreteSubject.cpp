#include "ConcreteSubject.h"

void ConcreteSubject::setData(const std::vector<std::vector<int>>& newData) {
    data = newData;
}

std::vector<std::vector<int>> ConcreteSubject::getData() const {
    return data;
}

void ConcreteSubject::attach(Observer* observer) {
    observers.push_back(observer);
}

void ConcreteSubject::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void ConcreteSubject::notify() {
    for (auto observer : observers) {
        observer->update(data);
    }
}
