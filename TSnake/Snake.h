#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <vector>

class Snake {
private:
    int m_XnewPosition = 0;
    int m_YnewPosition = 0;
    int m_size = 0;
    int m_vectorSize = 0;
    std::vector<int> m_XvectorPosition;
    std::vector<int> m_YvectorPosition;
    void ProcessSnake(int, int);
    void PrintSnake(int , int , int );
    

public:
    Snake();
    int GetSize();
    int GetXPosition();
    int GetYPosition();
    void RecastSnake(int, int, int);
    void Move(int, char, int , int, int);
    void Clean(int, int, int);
    std::vector<int> GetXVector();
    std::vector<int> GetYVector();
};