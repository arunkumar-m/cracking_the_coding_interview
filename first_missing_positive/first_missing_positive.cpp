/*
 * =====================================================================================
 *
 *       Filename:  first_missing_positive.cpp
 *
 *        Version:  1.0
 *        Created:  12/21/2013 00:21:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int firstMissingPositive(int A[], int n) {
    if (n == 0) {
        return 1;
    }
    int *B = new int[n];
    for (int i = 0; i < n; i++) {
        B[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (A[i] - 1 >= 0 && A[i] - 1 < n) {
            B[A[i] - 1] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (B[i] == 0) {
            delete[] B;
            return i + 1;
        }
    }
    delete[] B;
    return n + 1;
}

int main() {
    int arr1[] = {1,2,3};
    cout << firstMissingPositive(arr1, 3) << endl;
    int arr2[] = {3,4,-1,1,};
    cout << firstMissingPositive(arr2, 4) << endl;
    return 0;
}
