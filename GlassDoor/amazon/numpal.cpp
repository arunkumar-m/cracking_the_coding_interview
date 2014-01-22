/*
 * =====================================================================================
 *
 *       Filename:  numpal.cpp
 *
 *        Version:  1.0
 *        Created:  01/22/2014 00:28:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int reverseint(int n) {
    int r = 0;
    while (n > 0) {
        r = r * 10;
        r = r + n % 10;
        n /= 10;
    }
    return r;
}

bool numpal(int n) {
    int r = reverseint(n);
    return r == n;
}

int main() {
    cout << reverseint(10) << endl;
    cout << reverseint(19) << endl;
    return 0;
}
