/*
 * =====================================================================================
 *
 *       Filename:  search.cpp
 *
 *        Version:  1.0
 *        Created:  12/05/2013 20:53:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int search(int A[], int n, int target) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (A[mid] == target) {
            return mid;
        }
        if (A[left] <= A[mid]) {
            if (A[left] <= target && target <= A[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        else {
            if (A[mid] < target && target <= A[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int arr[] = {4,5,6,7,0,1,2};
    for (int i = 0; i < 10; i++) {
        cout << i << ": " << search(arr, 7, i) << endl;
    }
    return 0;
}
