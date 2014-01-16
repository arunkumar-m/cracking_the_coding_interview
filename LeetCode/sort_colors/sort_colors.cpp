/*
 * =====================================================================================
 *
 *       Filename:  sort_colors.cpp
 *
 *        Version:  1.0
 *        Created:  12/04/2013 20:34:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

void sortColors(int A[], int n) {
    int cnt[3] = {0,0,0}; // cnt[0]: red, cnt[1]: white, cnt[2]: blue.
    for (int i = 0; i < n; i++) {
        cnt[A[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[0] > 0) {
            A[i] = 0;
            cnt[0]--;
        }
        else if (cnt[1] > 0) {
            A[i] = 1;
            cnt[1]--;
        }
        else if (cnt[2] > 0) {
            A[i] = 2;
            cnt[2]--;
        }
    }
}

void printArr(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {2,0,2,1,2,1,0,0,1,2};
    sortColors(A, 10);
    printArr(A, 10);
    return 0;
}
