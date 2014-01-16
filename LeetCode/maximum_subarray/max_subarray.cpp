/*
 * =====================================================================================
 *
 *       Filename:  max_subarray.cpp
 *
 *        Version:  1.0
 *        Created:  11/30/2013 01:28:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int maxSubArray(int A[], int n) {
    int max_so_far = A[0];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > 0) {
            sum += A[i];
            if (sum > max_so_far) {
                 max_so_far = sum;
            }
        }
        else if (A[i] <= 0) {
            max_so_far = max(max_so_far, A[i]);
            if (sum + A[i] > 0) {
                sum += A[i];
            }
            else {
                sum = 0;
            }
        }
    }
    return max_so_far;
}

int main() {
    int A[] = {-2,1,-3,4,-1,-2,1,-5,4};
    cout << maxSubArray(A, 9) << endl;
    return 0;
}
