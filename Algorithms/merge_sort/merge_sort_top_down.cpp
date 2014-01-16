/*
 * =====================================================================================
 *
 *       Filename:  merge_sort_top_down.cpp
 *
 *        Version:  1.0
 *        Created:  12/17/2013 01:55:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

void copyArray(int *B, int begin, int end, int *A) {
    for (int i = begin; i <= end; i++) {
        A[i] = B[i];
    }
}

void topDownMerge(int *A, int begin, int mid, int end, int *B) {
    int bi = 0, ci = mid + 1;
    for (int i = begin; i <= end; i++) {
        if (bi <= mid && (ci > end || A[bi] <= A[ci])) {
            B[i] = A[bi++];
        }
        else {
            B[i] = A[ci++];
        }
    }
}

void topDownSplitMerge(int *A, int begin, int end, int *B) {
    if (end - begin < 1) return;
    int mid = begin + (end - begin) / 2;
    topDownSplitMerge(A, begin, mid, B);
    topDownSplitMerge(A, mid + 1, end, B);
    topDownMerge(A, begin, mid, end, B);
    copyArray(B, begin, end, A);
}

void printArr(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {5,3,2,6,1,4,7,10,9,8};
    int *B = new int[10];
    topDownSplitMerge(A, 0, 9, B);
    printArr(A, 10);
    return 0;
}
