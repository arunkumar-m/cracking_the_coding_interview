/*
 * =====================================================================================
 *
 *       Filename:  pow.cpp
 *
 *        Version:  1.0
 *        Created:  01/21/2014 00:46:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

double pow(double x, int n) {
    if (x == 0) return 1;
    if (n == 1) return x;
    double half = pow(x, n / 2);
    if (n % 2) {
        if (n > 0)
            return half * half * x;
        else
            return half * half / x;
    }
    else
        return half * half;
}

int main() {
    cout << pow(10, 10) << endl;
    cout << pow(-10, 3) << endl;
    return 0;
}
