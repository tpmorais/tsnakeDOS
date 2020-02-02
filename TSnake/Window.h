#ifndef WINDOW_HEADER
#define WINDOW_HEADER
#include <windows.h>
#include <iostream>

class Window {
private:
    int m_XconsoleSize = 1000;
    int m_YconsoleSize = 950;
    int m_collisionStatus;

public: 
    int m_XscreenSize;
    int m_YscreenSize;
    Window();
    int GetScreenSizeX();
    int GetScreenSizeY();
    void SetScreenSize(int, int);
    void PrintBackgroundScreen(int x_screen_size, int y_screen_size, int screen_print_control);
    void SetUpConsole();

};

#endif