#include "Window.h"

Window::Window() {
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, m_XconsoleSize, m_YconsoleSize, TRUE);
    SetUpConsole();
}

void Window::SetUpConsole() {
    system("cls");
    HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
    COORD pos;
    pos.X = 55;
    pos.Y = 0;
    SetConsoleCursorPosition(hConsole, pos);
    std::cout << "TSNAKE\n";
    for (int k_loop = 0; k_loop <= 119; k_loop++) {
        printf("=");
    }
    pos.X = 65;
    pos.Y = 50;
    SetConsoleCursorPosition(hConsole, pos);
    printf("H: Hard, N: Normal, E: Easy || Press Q to quit.\n\n");
    printf("Press Key to select difficulty: ");
}

int Window::GetScreenSizeX() {
    return m_XscreenSize;
}

int Window::GetScreenSizeY() {
    return m_YscreenSize;
}

void Window::SetScreenSize(int x, int y) {
    m_XscreenSize = x;
    m_YscreenSize = y;
}

void Window::PrintBackgroundScreen(int m_XscreenSize, int m_YscreenSize, int screen_print_control) {
    if (screen_print_control == 0) {
        HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
        COORD pos;
        for (int i_loop = 0; i_loop <= m_XscreenSize; i_loop++) {
            for (int j_loop = 0; j_loop <= m_YscreenSize; j_loop++) {
                if (i_loop == 0 && j_loop == 0) {
                    pos.X = j_loop;
                    pos.Y = i_loop;
                    SetConsoleCursorPosition(hConsole, pos);
                    std::cout << ".";
                }
                else if (i_loop == 0 && j_loop > 0 && j_loop < m_YscreenSize) {
                    pos.X = j_loop;
                    pos.Y = i_loop;
                    SetConsoleCursorPosition(hConsole, pos);
                    std::cout << ".";
                }
                else if (i_loop == 0 && j_loop == m_YscreenSize) {
                    pos.X = j_loop;
                    pos.Y = i_loop;
                    SetConsoleCursorPosition(hConsole, pos);
                    std::cout << ".";
                }
                else if (j_loop == 0 && i_loop > 0 && i_loop < m_XscreenSize) {
                    pos.X = j_loop;
                    pos.Y = i_loop;
                    SetConsoleCursorPosition(hConsole, pos);
                    std::cout << ".";
                }
                else if (j_loop == 0 && i_loop == m_XscreenSize) {
                    pos.X = j_loop;
                    pos.Y = i_loop;
                    SetConsoleCursorPosition(hConsole, pos);
                    std::cout << ".";
                }
                else if (j_loop == m_YscreenSize && i_loop < m_XscreenSize) {
                    pos.X = j_loop;
                    pos.Y = i_loop;
                    SetConsoleCursorPosition(hConsole, pos);
                    std::cout << ".";
                }
                else if (j_loop == m_YscreenSize && i_loop == m_XscreenSize) {
                    pos.X = j_loop;
                    pos.Y = i_loop;
                    SetConsoleCursorPosition(hConsole, pos);
                    std::cout << ".";
                }
                else if (j_loop > 0 && j_loop < m_YscreenSize &&
                    i_loop == m_XscreenSize) {
                    pos.X = j_loop;
                    pos.Y = i_loop;
                    SetConsoleCursorPosition(hConsole, pos);
                    std::cout << ".";
                }
            }
        }
        printf("\nPress Q to go back to main menu.");
    }
}