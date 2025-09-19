#include <iostream>
using namespace std;
#include "gcd.h"

int main() {
    int x, y;
    cout << "ВВЕДИТЕ ПЕРВОЕ ЧИСЛО: ";
    cin >> x;
    cout << "ВВЕДИТЕ ВТОРОЕ ЧИСЛО: ";
    cin >> y;
    int result = gcd(x, y);
    if (result == -1) {
        cout << "НОД двух нулей не определен";
    } else
    {
        cout << result;
    }
    
}
