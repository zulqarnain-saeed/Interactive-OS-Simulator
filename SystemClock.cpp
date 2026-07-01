#include "SystemClock.h"


SystemClock* SystemClock::instance = nullptr;


SystemClock::SystemClock() : time(0) {}


SystemClock* SystemClock::getInstance() {
    if (instance == nullptr) {
        instance = new SystemClock();
    }
    return instance;
}

int SystemClock::getTime() const {
    return time;
}

void SystemClock::tick(int increment) {
    time += increment;
}

void SystemClock::reset() {
    time = 0;
}