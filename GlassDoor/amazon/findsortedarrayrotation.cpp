/*
 * =====================================================================================
 *
 *       Filename:  findsortedarrayrotation.cpp
 *
 *        Version:  1.0
 *        Created:  01/22/2014 12:10:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int findsortedarrayrotation(int A[], int n) {
    int L = 0;
    int R = n - 1;
    while (A[L] > A[R]) {
        int M = L + (R - L) / 2;
        if (A[M] > A[R]) {
            L = M + 1;
        }
        else {
            R = M;
        }
    }
    return L;
}

int main() {
    int arr[] = {5,6,7,8,9,0,1,2,3,4};
    int n = 10;
    cout << findsortedarrayrotation(arr, n) << endl;
    return 0;
}
