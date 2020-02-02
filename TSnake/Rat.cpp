#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <vector>
#include "Game.h"

Rat::Rat() {
    
}

void Rat::SetNewPosition(int snake_size, std::vector<int> x_snake_vector_position, std::vector<int> y_snake_vector_position, int x_screen_size, int y_screen_size) {
    srand(time(NULL));

    std::vector<int> XY = GeneratePosition(x_screen_size, y_screen_size);
    
    while (CheckValidPosition(snake_size, x_snake_vector_position, y_snake_vector_position, XY[0], XY[1]) != true) {
        XY = GeneratePosition(x_screen_size, y_screen_size);
    }

    m_Xposition = XY[0];
    m_Yposition = XY[1];

}

std::vector<int> Rat::GeneratePosition(int x_screen_size, int y_screen_size) {
    m_Xposition_temp = rand() % x_screen_size;
    m_Yposition_temp = rand() % y_screen_size;

    if (m_Xposition_temp == 0 || m_Xposition_temp == 1) m_Xposition_temp = 2;

    if (m_Xposition_temp == x_screen_size || m_Xposition_temp == x_screen_size - 1) m_Xposition_temp = x_screen_size - 2;

    if (m_Yposition_temp == y_screen_size || m_Yposition_temp == y_screen_size - 1) m_Yposition_temp = y_screen_size - 2;

    if (m_Yposition_temp == 0 || m_Yposition_temp == 1) m_Yposition_temp = 2;

    std::vector<int> temp; 
    temp.push_back(m_Xposition_temp);
    temp.push_back(m_Yposition_temp);
    return temp;    
}

bool Rat::CheckValidPosition(int snake_size, std::vector<int> x_snake_vector_position, std::vector<int> y_snake_vector_position, int m_Xposition_temp, int m_Yposition_temp) {
    for (int k_loop = 0; k_loop <= snake_size; k_loop++) {
        if (x_snake_vector_position[k_loop] == m_Xposition_temp && y_snake_vector_position[k_loop] == m_Yposition_temp) return false;
    }
    return true;
}

void Rat::Print(int x_screen_size) {
    HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
    COORD pos;
    pos.X = m_Yposition;
    pos.Y = m_Xposition;
    SetConsoleCursorPosition(hConsole, pos);
    std::cout << "*";
    pos.X = 0;
    pos.Y = x_screen_size + 3;
    SetConsoleCursorPosition(hConsole, pos);
    std::cout << "";
}

int Rat::GetXPosition() {
    return m_Xposition;
}

int Rat::GetYPosition() {
    return m_Yposition;
}

void Rat::Clean(int x_screen_size) {
    HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
    COORD pos;
    pos.X = m_Yposition;
    pos.Y = m_Xposition;
    SetConsoleCursorPosition(hConsole, pos);
    std::cout << " ";
    pos.X = 0;
    pos.Y = x_screen_size + 3;
    SetConsoleCursorPosition(hConsole, pos);
    std::cout << "";
}

void Rat::Refresh(int snake_size, std::vector<int> snakeXvector, std::vector<int> snakeYvector, int Xscreen_size, int Yscreen_size) {
    SetNewPosition(snake_size, snakeXvector, snakeYvector, Xscreen_size, Yscreen_size);
    Clean(Xscreen_size);
    Print(Xscreen_size);
}