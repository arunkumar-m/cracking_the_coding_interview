/*
 * =====================================================================================
 *
 *       Filename:  climb_stairs.cpp
 *
 *        Version:  1.0
 *        Created:  11/28/2013 23:54:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    int *table = new int[n + 1];
    for (int i = 0; i < n; i++) {
        table[i] = 0;
    }
    table[0] = 0;
    table[1] = 1;
    table[2] = 2;
    for (int i = 3; i <= n; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n];
}

int main() {
    cout << climbStairs(0) << endl;
    cout << climbStairs(1) << endl;
    cout << climbStairs(2) << endl;
    cout << climbStairs(3) << endl;
    cout << climbStairs(4) << endl;
    cout << climbStairs(5) << endl;
    cout << climbStairs(6) << endl;
    cout << climbStairs(7) << endl;
    cout << climbStairs(8) << endl;
    cout << climbStairs(9) << endl;
    return 0;
}
