#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <chrono>

class Timer {
public:
    Timer();
    void start();
    double elapsedMs() const;
private:
    std::chrono::high_resolution_clock::time_point t0;
};

#endif
