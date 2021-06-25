#include "example.hpp"

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