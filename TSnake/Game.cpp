#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <iostream>
#include <thread> 
#include "Game.h"

void MovementThread(Timer* timer, Game* game, int difficult) {
    timer->Start();
    while (timer->CheckStatus() == true) {
        if (timer->ElapsedMilliseconds() > difficult) {
            game->Update();
            timer->Start();
        }
    }
    timer->Stop();
}

Game::Game() {
    SetScreenSize(50, 100);
    SetLevel();
}

Game::~Game() {
    FinishGame();
}

void Game::StartGame() {
    system("cls");
    m_keyDirection = 's';
    m_screenPrintControl = 0;
    m_status = 1;

    ptr_Snake = new Snake();
    ptr_Snake->RecastSnake(m_collider, m_XscreenSize, m_screenPrintControl);

    ptr_Rat = new Rat();
    ptr_Rat->SetNewPosition(ptr_Snake->GetSize(), ptr_Snake->GetXVector(), ptr_Snake->GetYVector(), m_XscreenSize, m_YscreenSize);
    PrintBackgroundScreen(m_XscreenSize, m_YscreenSize, m_screenPrintControl);
    ptr_Rat->Print(m_XscreenSize);
    
    ptr_Timer = new Timer();
    ptr_Timer->Activate();
    std::thread t (MovementThread, std::ref(ptr_Timer), this, m_difficult);
    t.detach();

    ptr_Collision = new Collision();
    m_running = true;
    Controller(t);

}

void Game::Controller(std::thread &t) {
    while (m_running) {
     
    }
    t.~thread();
    FinishGame();
    SetLevel();
}

void Game::FinishGame() {
    system("cls");
    ptr_Timer->Deactivate();
    delete ptr_Snake;
    delete ptr_Rat;
    delete ptr_Timer;
    delete ptr_Collision;
}

void Game::SetLevel() {
    SetUpConsole();
    m_status = 0;
    char menu_key_press_win;
    menu_key_press_win = _getch();
    if (menu_key_press_win == 'H' || menu_key_press_win == 'h') {
        m_difficult = 30;
    } else if (menu_key_press_win == 'N' || menu_key_press_win == 'n') {
        m_difficult = 60;
    } else if (menu_key_press_win == 'E' || menu_key_press_win == 'e') {
        m_difficult = 90;
    } else if (menu_key_press_win == 'Q' || menu_key_press_win == 'q') {
        printf("\n\n\n");
        exit(0);
    }
    StartGame();
}


char Game::VerifyControlKey(int snake_size, char press_m_keyDirection) {
    char last_key_press_win;
    while (_kbhit()) {
        last_key_press_win = press_m_keyDirection;
        press_m_keyDirection = _getch();
        if (last_key_press_win == 'w' &&
            press_m_keyDirection == 's' && snake_size >= 1) {
            press_m_keyDirection = 'w';
        }
        else if (last_key_press_win == 's' &&
            press_m_keyDirection == 'w' && snake_size >= 1) {
            press_m_keyDirection = 's';
        }
        else if (last_key_press_win == 'a' &&
            press_m_keyDirection == 'd' && snake_size >= 1) {
            press_m_keyDirection = 'a';
        }
        else if (last_key_press_win == 'd' &&
            press_m_keyDirection == 'a' && snake_size >= 1) {
            press_m_keyDirection = 'd';
        }
        else if (press_m_keyDirection == 'q') {
            m_running = false;
            
        }
        else if (press_m_keyDirection != 'd' && press_m_keyDirection != 'a' &&
            press_m_keyDirection != 's' && press_m_keyDirection != 'w' &&
            press_m_keyDirection != 'q') {
            press_m_keyDirection = last_key_press_win;
        }
    }
    return press_m_keyDirection;
}

void Game::CollisionSystem() {
    if (ptr_Collision->CheckMatrixCollision(ptr_Snake->GetXPosition(), ptr_Snake->GetYPosition(), ptr_Rat->GetXPosition(), ptr_Rat->GetYPosition())) {
        m_collider = 1;
        ptr_Rat->Refresh(ptr_Snake->GetSize(), ptr_Snake->GetXVector(), ptr_Snake->GetYVector(), m_XscreenSize, m_YscreenSize);
    } else {
        for (int k_loop = 0; k_loop <= ptr_Snake->GetSize(); k_loop++) {
            if (ptr_Snake->GetXVector()[k_loop] == ptr_Snake->GetXPosition() && ptr_Snake->GetYVector()[k_loop] == ptr_Snake->GetYPosition()) {
                m_collider = 1;
                m_running = false;
            }
        }
        m_collider = 0;
    }
}

void Game::Update() {
    ptr_Snake->Move(m_collider, m_keyDirection, m_XscreenSize, m_YscreenSize, m_screenPrintControl);
    CollisionSystem();
    for (int k_loop = 0; k_loop <= ptr_Snake->GetSize(); k_loop++) {
        ptr_Snake->Clean(ptr_Snake->GetXVector()[k_loop], ptr_Snake->GetYVector()[k_loop], m_XscreenSize);
    }
    ptr_Snake->RecastSnake(m_collider, m_XscreenSize, m_screenPrintControl);
    m_keyDirection = VerifyControlKey(ptr_Snake->GetSize(), m_keyDirection);
}
