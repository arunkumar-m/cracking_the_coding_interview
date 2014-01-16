/*
 * =====================================================================================
 *
 *       Filename:  pow_x_n.cpp
 *
 *        Version:  1.0
 *        Created:  11/29/2013 00:18:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <cmath>
using namespace std;

// great improvement for recursive function calls
// less computation
double pow(double x, int n) {
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
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

// Another beautiful solution
/*double pow(double x, int n) {
    unsigned m = abs((double)n);
    double ret = 1;
    for (; m; x *= x, m >>= 1) {
        cout << m << " " << x << " " << ret << endl;
        if (m & 1)
            ret *= x;
    }
    return n > 0 ? ret : 1 / ret;
}*/

int main() {
    cout << pow(2, 3) << endl;
    cout << pow(2, -3) << endl;
    cout << pow(0.00001, 2147483647) << endl;
    cout << pow(1.00000, -2147483648) << endl;
    return 0;
}
