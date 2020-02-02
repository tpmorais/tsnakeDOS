#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <thread>
#include "Window.h";
#include "Rat.h";
#include "Snake.h";
#include "Timer.h"
#include "Collision.h"

class Game : public Window {
private:
    int m_difficult = 60;
    int m_collider;
    int m_screenPrintControl;
    int m_status;
    bool m_running;
    char m_keyDirection;

    void SetLevel();
    void StartGame();
    char VerifyControlKey(int, char);
    void CollisionSystem();
    void Controller(std::thread& );
    void FinishGame();

    Rat * ptr_Rat;
    Snake *ptr_Snake;
    Timer *ptr_Timer;
    Collision *ptr_Collision;

public:
    Game();
    ~Game();
    void Move();

};