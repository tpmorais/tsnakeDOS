#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>

class Timer {
public:
    void Start();
    void Stop();
    void Activate();
    void Deactivate();
    bool CheckStatus();
    double ElapsedMilliseconds();

private:
    std::chrono::time_point<std::chrono::system_clock> m_startTime;
    std::chrono::time_point<std::chrono::system_clock> m_endTime;
    bool m_bRunning = false;
    bool m_activated = false;
};

