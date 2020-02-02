#include "Timer.h"

void Timer::Start() {
    m_startTime = std::chrono::system_clock::now();
    m_bRunning = true;
}

void Timer::Stop() {
    m_endTime = std::chrono::system_clock::now();
    m_bRunning = false;
}

double Timer::ElapsedMilliseconds() {
    std::chrono::time_point<std::chrono::system_clock> endTime;

    if (m_bRunning) {
        endTime = std::chrono::system_clock::now();
    } else {
        endTime = m_endTime;
    }
    return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_startTime).count();
}

void Timer::Activate() {
    m_activated = true;
}

void Timer::Deactivate() {
    m_activated = false;
}

bool Timer::CheckStatus() {
    return m_activated;
}