/*
 * =====================================================================================
 *
 *       Filename:  total_n_queens.cpp
 *
 *        Version:  1.0
 *        Created:  12/16/2013 14:54:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

// diag
bool check(int board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (board[i] + i == board[j] + j || board[i] - i == board[j] - j) {
                return false;
            }
        }
    }

    return true;
}

void nqueens(int board[], int n, int curr, int &cnt, int *row, int **diag) {
    if (curr == n) {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        board[curr] = i;
        if (row[i] == 0 && diag[i][curr] == 0) {
            row[i] = 1;
            for (int j = 0; j < n; j++) {
                if (curr + i - j < n && curr + i - j >= 0) {
                    diag[j][curr + i - j]++;
                }
                if (curr - i + j < n && curr - i + j >= 0) {
                    diag[j][curr - i + j]++;
                }
            }
            nqueens(board, n, curr + 1, cnt, row, diag);
            row[i] = 0;
            for (int j = 0; j < n; j++) {
                if (curr + i - j < n && curr + i - j >= 0) {
                    diag[j][curr + i - j]--;
                }
                if (curr - i + j < n && curr - i + j >= 0) {
                    diag[j][curr - i + j]--;
                }
            }
        }
    }
}

int totalNQueens(int n) {
    int *board = new int[n];
    int *row = new int[n];
    int **diag = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = -1;
        row[i] = 0;
        diag[i] = new int[n];
        for (int j = 0; j < n; j++) {
            diag[i][j] = 0;
        }
    }
    int cnt = 0;
    nqueens(board, n, 0, cnt, row, diag);
    return cnt;
}

int main() {
    cout << totalNQueens(12) << endl;
    return 0;
}
