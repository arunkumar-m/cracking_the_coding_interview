/*
 * =====================================================================================
 *
 *       Filename:  diff.cpp
 *
 *        Version:  1.0
 *        Created:  12/30/2013 00:32:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

void diff(float **A, int l, float **B, int m, float **C, int n) {
    int ai = 0;
    int bi = 0;
    for (int i = 0; i < n; i++) {
        int time = 10 * i;
        while (ai < l && A[ai][0] <= time) ai++;
        ai--;
        while (bi < m && B[bi][0] <= time) bi++;
        bi--;

        C[i][0] = time;
        C[i][1] = B[bi][1] - A[ai][1];
    }
}

void printArray(float **A, int len) {
    for (int i = 0; i < len; i++) {
        cout << A[i][0] << " " << A[i][1] << endl;
    }
}

int main() {
    float **A = new float*[5];
    for (int i = 0; i < 5; i++) {
        A[i] = new float[2];
    }
    A[0][0] = 0;
    A[0][1] = 900;
    A[1][0] = 4;
    A[1][1] = 1200;
    A[2][0] = 15;
    A[2][1] = 1300;
    A[3][0] = 230;
    A[3][1] = 1400;
    A[4][0] = 500;
    A[4][1] = 1800;
    float **B = new float*[4];
    for (int i = 0; i < 4; i++) {
        B[i] = new float[2];
    }
    B[0][0] = 0;
    B[0][1] = 1300;
    B[1][0] = 10;
    B[1][1] = 1400;
    B[2][0] = 30;
    B[2][1] = 1500;
    B[3][0] = 198;
    B[3][1] = 1600;
    float **C = new float*[50];
    for (int i = 0; i < 50; i++) {
        C[i] = new float[2];
    }
    diff(A, 5, B, 4, C, 30);
    printArray(C, 30);
    return 0;
}
