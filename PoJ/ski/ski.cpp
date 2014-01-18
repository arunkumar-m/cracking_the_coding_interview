/*
 * =====================================================================================
 *
 *       Filename:  ski.cpp
 *
 *        Version:  1.0
 *        Created:  01/17/2014 16:02:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int R;
int C;
int A[100][100];
int explored[100][100] = {0};
int mem[100][100] = {0};

int visit(int i, int j) {
    if (explored[i][j]) return mem[i][j];
    explored[i][j] = 1;
    int length = 0;
    // visit i-1, j
    if (i - 1 >= 0 && A[i][j] > A[i - 1][j]) {
        length = max(length, visit(i - 1, j));
    }
    // visit i+1, j
    if (i + 1 < R && A[i][j] > A[i + 1][j]) {
        length = max(length, visit(i + 1, j));
    }
    // visit i, j-1
    if (j - 1 >= 0 && A[i][j] > A[i][j - 1]) {
        length = max(length, visit(i, j - 1));
    }
    // visit i, j+1
    if (j + 1 < C && A[i][j] > A[i][j + 1]) {
        length = max(length, visit(i, j + 1));
    }
    mem[i][j] = length + 1;
    return length + 1;
}

void printA() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void printMem() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << mem[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // ifstream fin("ski.in");
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
            mem[i][j] = 1;
        }
    }
    // fin.close();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (explored[i][j] == 0) {
                visit(i, j);
            }
        }
    }
    int maxLen = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            maxLen = max(maxLen, mem[i][j]);
        }
    }
    cout << maxLen << endl;
    return 0;
}
