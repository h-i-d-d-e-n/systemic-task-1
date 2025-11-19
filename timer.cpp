#include "timer.h"

Timer::Timer() {
    t0 = std::chrono::high_resolution_clock::now();
}

void Timer::start() {
    t0 = std::chrono::high_resolution_clock::now();
}

double Timer::elapsedMs() const {
    auto t1 = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(t1 - t0).count();
}
