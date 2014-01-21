/*
 * =====================================================================================
 *
 *       Filename:  sqrt.cpp
 *
 *        Version:  1.0
 *        Created:  01/21/2014 00:56:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

/* consider the invariant!
 * left <= right
 * return right
 **/
int sqrt(int x) {
    if (x == 0) return 0;
    int left = 0;
    int right = x;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (mid * mid == x) return mid;
        if (mid * mid < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return right;
}

int main() {
    for (int i = 0; i < 100; i += 10) {
        cout << i << ": " << sqrt(i) << endl;
    }
    return 0;
}
