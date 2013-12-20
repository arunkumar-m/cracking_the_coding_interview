/*
 * =====================================================================================
 *
 *       Filename:  solve_n_queens.cpp
 *
 *        Version:  1.0
 *        Created:  12/19/2013 20:10:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

int cnt = 1;

void nqueens(int curr, int n, int *board, int *row, int *ldiag, int *rdiag, vector<vector<string> > &results) {
    if (curr == n + 1) { // record solution
        vector<string> vec;
        for (int i = 1; i <= n; i++) {
            string s;
            int pos = board[i];
            s.append(pos - 1, '.');
            s.append(1, 'Q');
            s.append(n - pos, '.');
            vec.push_back(s);
        }
        results.push_back(vec);
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (row[i] == 0 && ldiag[curr + i] == 0 && rdiag[curr - i + n] == 0) {
                // mark
                ldiag[curr + i] = 1;
                rdiag[curr - i + n] = 1;
                row[i] = 1;

                board[curr] = i;
                nqueens(curr + 1, n, board, row, ldiag, rdiag, results);

                // unmark
                ldiag[curr + i] = 0;
                rdiag[curr - i + n] = 0;
                row[i] = 0;
            }
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > results;
    int *board = new int[n + 1];
    int *row = new int[n + 1];
    int *ldiag = new int[2 * n + 1];
    int *rdiag = new int[2 * n + 1];
    for (int i = 0; i <= n; i++) {
        board[i] = 0;
        row[i] = 0;
    }
    for (int i = 0; i < 2 * n + 1; i++) {
        ldiag[i] = 0;
        rdiag[i] = 0;
    }
    nqueens(1, n, board, row, ldiag, rdiag, results);
    return results;
}

void printVV(vector<vector<string> > vv) {
    for (int i = 0; i < vv.size(); i++) {
        cout << "#### BEGIN " << i << " ####" << endl;
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << endl;
        }
        cout << "#### END " << i << " ####" << endl;
    }
}

int main() {
    vector<vector<string> > vv = solveNQueens(5);
    printVV(vv);
    return 0;
}
