/*
 * =====================================================================================
 *
 *       Filename:  trap.cpp
 *
 *        Version:  1.0
 *        Created:  12/05/2013 21:32:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int trap(int A[], int n) {
    int *left = new int[n];
    int *right = new int[n];
    int left_max = 0;
    for (int i = 0; i < n; i++) {
        left[i] = left_max;
        left_max = max(left_max, A[i]);
    }

    int right_max = 0;
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += max(0, min(right_max, left[i]) - A[i]);
        right_max = max(right_max, A[i]);
    }

    delete[] left;
    delete[] right;

    return sum;
}

int main() {
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(arr, 12) << endl;
    return 0;
}
