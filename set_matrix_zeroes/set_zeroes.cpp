/*
 * =====================================================================================
 *
 *       Filename:  set_zeroes.cpp
 *
 *        Version:  1.0
 *        Created:  12/02/2013 21:31:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int> > &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int *row = new int[m];
    int *col = new int[n];
    for (int i = 0; i < m; i++) {
        row[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        col[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (row[i] == 1) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (col[i] == 1) {
            for (int j = 0; j < m; j++) {
                matrix[j][i] = 0;
            }
        }
    }
}

void printVV(vector<vector<int> > &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[4][4] = {
        {1,2,3,4},
        {5,6,0,8},
        {9,10,11,12},
        {13,14,15,16},
    };
    vector<vector<int> > matrix(4, vector<int>(4));
    for (int i = 0; i < 4; i++) {
        matrix[i].assign(arr[i], arr[i] + 4);
    }
    setZeroes(matrix);
    printVV(matrix);
    return 0;
}
