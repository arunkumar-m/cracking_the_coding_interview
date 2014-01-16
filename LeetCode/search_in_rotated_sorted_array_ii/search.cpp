/*
 * =====================================================================================
 *
 *       Filename:  search.cpp
 *
 *        Version:  1.0
 *        Created:  12/04/2013 21:05:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

bool search(int A[], int n, int target) {
    int left = 0, right = n - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (A[mid] == target || A[left] == target || A[right] == target) {
            return true;
        }
        else if (A[left] <= A[mid]) {
            if (target < A[mid] && target > A[left]) {
                right = mid - 1;
                continue;
            }
        }
        else if (A[right] >= A[mid]) {
            if (target > A[mid] && target < A[right]) {
                left = mid + 1;
                continue;
            }
        }
        left++;
        right--;
    }
    return false;
}

int main() {
    int arr[] = {7,8,9,10,1,1,3,4,5,6};
    cout << search(arr, 10, 11) << endl;
    int arr1[] = {1};
    cout << search(arr1, 1, 1) << endl;
    return 0;
}
