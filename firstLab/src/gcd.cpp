#include "gcd.h"

int gcd(int x, int y) {
    if (x == 0 && y == 0) {
        return -1;
    }
    int a, b, temp;
    if (x >= y) {
        a = x;
        b = y; 
    } else {
        a = y;
        b = x; 
    }
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}