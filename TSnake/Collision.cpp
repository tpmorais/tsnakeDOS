#include "Collision.h"

bool Collision::CheckMatrixCollision(int Xone, int Yone, int Xtwo, int Ytwo) {
    if (Xone == Xtwo && Yone == Ytwo) {
        return true;
    }
    return false;
}