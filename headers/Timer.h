#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <functional>
#include <thread>


class Timer
{
    // const long Infinite = -1L;
    std::thread Th1;
    bool Alive = false;
    long CallNumber = -1L; // Repeating timer
    long repeat_count = -1L;
    std::chrono::milliseconds interval = std::chrono::milliseconds(0);
    std::function<void(void)> funct = nullptr;

    void SleepAndRun()
    {
        std::this_thread::sleep_for(interval);
        if (Alive)
            funct();
    }
    void Th1Func()
    {
        if (CallNumber == Infinite)
            while (Alive)
                SleepAndRun();
        else
            while (repeat_count--)
                SleepAndRun();
    }

public:
    static const long Infinite = -1L;
    Timer() {}
    Timer(const std::function<void(void)> &f) : funct(f) {}
    Timer(const std::function<void(void)> &f,
          const unsigned long &i,
          const long repeat = Timer::Infinite) : funct(f),
                                                 interval(std::chrono::milliseconds(i)),
                                                 CallNumber(repeat) {}
    void Start(bool Async = true)
{
    if (IsAlive())
        return;
    Alive = true;
    repeat_count = CallNumber;
    if (Async)
        Th1 = std::thread(&Timer::Th1Func, this); // Pass pointer to `this`
    else
        this->Th1Func();
}

    void Stop()
    {
        Alive = false;
        Th1.join();
    }
    bool IsAlive() const { return Alive; }
    void SetFunction(const std::function<void(void)> &f)
    {
        funct = f;
    }

    void RepeatCount(const long r)
    {
        if (Alive)
            return;
        CallNumber = r;
    }
    long GetLeftCount() const { return repeat_count; }
    long RepeatCount() const { return CallNumber; }

    void SetInterval(const unsigned long &i)
    {
        if (Alive)
            return;
        interval = std::chrono::milliseconds(i);
    }
    unsigned long GetInterval() const { return interval.count(); }

    std::function<void(void)> GetFunction() const { return funct; }
    long GetCallNumber() const { return CallNumber; }
    ~Timer()
    {
        if (Alive)
            Stop();
    }
};

#endif
