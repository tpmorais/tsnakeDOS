#include <windows.h>
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <vector>
#include "config.h";

class Rat {
private:
    int m_Xposition = 0;
    int m_Yposition = 0;
    int m_Xposition_temp = 0;
    int m_Yposition_temp = 0;
    bool CheckValidPosition(int, std::vector<int>, std::vector<int>, int, int);
    std::vector<int> GeneratePosition(int, int);

public:
    Rat();
    void SetNewPosition(int, std::vector<int> , std::vector<int>, int, int);
    void Print(int);
    int  GetXPosition();
    int  GetYPosition();
    void Clean(int);
    void Refresh(int, std::vector<int>, std::vector<int>, int, int);

};
