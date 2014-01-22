/*
 * =====================================================================================
 *
 *       Filename:  div.cpp
 *
 *        Version:  1.0
 *        Created:  01/21/2014 16:05:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

// only positive values
int divide(int dividend, int divisor) {
    int x = dividend;
    int y = divisor;
    if (x < y) return 0;
    if (x == y) return 1;
    int ret = 0;
    int i = 1;
    while (x > y) {
        y <<= 1;
        i *= 2;
    }
    y >>= 1;
    i /= 2;
    return i + divide(x - y, divisor);
}

int main() {
    cout << divide(8, 6) << endl;
    cout << divide(13, 6) << endl;
    cout << divide(18, 6) << endl;
    cout << divide(30, 6) << endl;
    cout << divide(720, 6) << endl;
    return 0;
}
