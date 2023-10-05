#pragma once

#include "Observer.h"
#include <list>

using namespace std;
class Subject {
private:
    list<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        observers.remove(observer);
    }

    void notify() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};
