#include "example.hpp"

#include <math.h>

// for windows build
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

bool f() {
    return false;
}

int f2(int x) {
    return x;
}

int MAC(int x, int y, int &sum) {
    sum += x * y;
    return sum;
}

int Square(int x) {
    return x * x;
}

double circleSquare(int radius)
{
    return radius * M_PI;
}
