/*
 * =====================================================================================
 *
 *       Filename:  merge_sort_bottom_up.cpp
 *
 *        Version:  1.0
 *        Created:  12/17/2013 04:07:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

void bottomUpSort(int n, int A[], int B);
void bottomUpMerge(int A[], int left, int right, int end, int B[]);
void copyArray(int A[], int B[], int n);

// copy array B's elements to A
void copyArray(int A[], int B[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

void bottomUpSort(int n, int A[], int B[]) {
    int width;
    for (width = 1; width < n; width *= 2) {
        int i;
        for (i = 0; i < n; i += 2 * width) {
            bottomUpMerge(A, i, min(i + width, n), min(i + 2 * width, n), B);
        }
        copyArray(A, B, n);
    }
}

void bottomUpMerge(int A[], int left, int right, int end, int B[]) {
    int i0 = left;
    int i1 = right;
    for (int j = left; j < end; j++) {
        if (i0 < right && (i1 >= end || A[i0] < A[i1])) {
            B[j] = A[i0++];
        }
        else {
            B[j] = A[i1++];
        }
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {6,3,5,2,1,4};
    bottomUpSort(6, arr, new int[6]);
    printArray(arr, 6);
    return 0;
}
