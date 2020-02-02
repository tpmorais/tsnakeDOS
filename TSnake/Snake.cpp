#include <windows.h>
#include <iostream>
#include "Snake.h"

Snake::Snake() {
	m_XvectorPosition.resize(25);
	m_YvectorPosition.resize(25);


	m_XvectorPosition[0] = 1;
	m_YvectorPosition[0] = 1;
}

int Snake::GetXPosition() {
    return m_XnewPosition;
}

int Snake::GetYPosition() {
    return m_YnewPosition;
}

int Snake::GetSize() {
	return m_size;
}

std::vector<int> Snake::GetXVector() {
	return m_XvectorPosition;
}

std::vector<int> Snake::GetYVector() {
	return m_YvectorPosition;
}

void Snake::RecastSnake(int collision_status, int x_screen_size, int screen_print_control) {
    if (collision_status == 1) {
        m_size++;
        for (int k_loop = m_size; k_loop >= 0; k_loop--) {
            if (k_loop == 0) {
                m_XvectorPosition[k_loop] = m_XnewPosition;
                m_YvectorPosition[k_loop] = m_YnewPosition;
            }
            else {
                m_XvectorPosition[k_loop] = m_XvectorPosition[k_loop - 1];
                m_YvectorPosition[k_loop] = m_YvectorPosition[k_loop - 1];
            }
        }
    }
    else {
        for (int k_loop = m_size; k_loop >= 0; k_loop--) {
            if (k_loop == 0) {
                m_XvectorPosition[k_loop] = m_XnewPosition;
                m_YvectorPosition[k_loop] = m_YnewPosition;
            }
            else {
                m_XvectorPosition[k_loop] = m_XvectorPosition[k_loop - 1];
                m_YvectorPosition[k_loop] = m_YvectorPosition[k_loop - 1];
            }
        }
    }
    m_vectorSize++;
    m_XvectorPosition.resize(m_vectorSize);
    m_YvectorPosition.resize(m_vectorSize);
    ProcessSnake(x_screen_size, screen_print_control);
}


void Snake::ProcessSnake(int x_screen_size, int screen_print_control) {
    for (int k_loop = 0; k_loop <= m_size; k_loop++) {
        if (screen_print_control == 0) {
            PrintSnake(m_XvectorPosition[k_loop], m_YvectorPosition[k_loop], x_screen_size);
            screen_print_control = 1;
        }
        else {
            PrintSnake(m_XvectorPosition[k_loop], m_YvectorPosition[k_loop], x_screen_size);
        }
    }
}

void Snake::PrintSnake(int x_snake_vector_position, int y_snake_vector_position, int x_screen_size) {
    HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
    COORD pos;
    pos.X = y_snake_vector_position;
    pos.Y = x_snake_vector_position;
    SetConsoleCursorPosition(hConsole, pos);
    std::cout << "o";
    pos.X = 0;
    pos.Y = x_screen_size + 3;
    SetConsoleCursorPosition(hConsole, pos);
    std::cout << "";
}

void Snake::Move(int collision, char key, int x_screen_size, int y_screen_size, int screen_print_control) {
    collision = 0;
    if (key == 'd') {
        m_YnewPosition++;
    }
    else if (key == 'w') {
        m_XnewPosition--;
    }
    else if (key == 'a') {
        m_YnewPosition--;
    }
    else if (key == 's') {
        m_XnewPosition++;
    }
    if (m_XnewPosition < 1) {
        m_XnewPosition = x_screen_size - 1;
    }
    else if (m_XnewPosition == x_screen_size) {
        m_XnewPosition = 1;
    }
    if (m_YnewPosition < 1) {
        m_YnewPosition = y_screen_size - 1;
    }
    else if (m_YnewPosition == y_screen_size) {
        m_YnewPosition = 1;
    }   
}

void Snake::Clean(int m_XvectorPosition, int m_YvectorPosition, int x_screen_size) {
    HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
    COORD pos;
    pos.X = m_YvectorPosition;
    pos.Y = m_XvectorPosition;
    SetConsoleCursorPosition(hConsole, pos);
    std::cout << " ";
    pos.X = 0;
    pos.Y = x_screen_size + 3;
    SetConsoleCursorPosition(hConsole, pos);
    std::cout << "";
}