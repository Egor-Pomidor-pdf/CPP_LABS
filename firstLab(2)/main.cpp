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
        cout << "Ошибка: НОД(0,0) не определен";
    } else
    {
        cout << result;
    }
    
}
