/*
 * =====================================================================================
 *
 *       Filename:  search_insert.cpp
 *
 *        Version:  1.0
 *        Created:  11/27/2013 12:57:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int searchInsert(int A[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (A[mid] == target) {
            return mid;
        }
        else if (A[mid] < target) {
            left = mid + 1;
        }
        else if (A[mid] > target) {
            right = mid - 1;
        }
    }
    return A[(left + right) / 2] < target ? ((left + right) / 2 + 1) : ((left + right) / 2);
}

int main() {
    int A[] = {1,3,5,6};
    cout << searchInsert(A, 4, 5) << endl;
    cout << searchInsert(A, 4, 2) << endl;
    cout << searchInsert(A, 4, 7) << endl;
    cout << searchInsert(A, 4, 0) << endl;
    return 0;
}
