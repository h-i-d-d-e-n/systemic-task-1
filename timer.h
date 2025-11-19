#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include "listAndDeque.h"
#include "fileGenerate.h"
#include "mylib.h"
#include "person.h"
#include "timer.h"

class Timer {
public:
    Timer();
    void start();
    double elapsedMs() const;
private:
    std::chrono::high_resolution_clock::time_point t0;
};

#endif
