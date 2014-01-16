/*
 * =====================================================================================
 *
 *       Filename:  selection.cpp
 *
 *        Version:  1.0
 *        Created:  12/17/2013 04:50:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int partition(int A[], int begin, int end) {
    int pivotValue = A[end];
    int pivotIndex = begin - 1;
    for (int i = begin; i < end; i++) {
        if (A[i] < pivotValue) {
            pivotIndex++;
            swap(A[i], A[pivotIndex]);
        }
    }
    pivotIndex++;
    swap(A[end], A[pivotIndex]);
    return pivotIndex;
}

int find_kth_smallest(int A[], int begin, int end, int k) {
    int pivotIndex = partition(A, begin, end);
    if (pivotIndex == k - 1) {
        return A[pivotIndex];
    }
    else if (pivotIndex < k - 1) {
        return find_kth_smallest(A, pivotIndex + 1, end, k - pivotIndex - 1);
    }
    else {
        return find_kth_smallest(A, begin, pivotIndex - 1, k);
    }
}

int main() {
    int A[] = {6,4,2,1,3,5};
    for (int i = 1; i <= 6; i++) {
        cout << find_kth_smallest(A, 0, 5, i) << endl;
    }
    return 0;
}
