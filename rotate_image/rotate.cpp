/*
 * =====================================================================================
 *
 *       Filename:  rotate.cpp
 *
 *        Version:  1.0
 *        Created:  12/01/2013 18:46:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void transpose(vector<vector<int> > &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void mirror(vector<vector<int> > &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}

void rotate(vector<vector<int> > &matrix) {
    transpose(matrix);
    mirror(matrix);
}

void printVV(vector<vector<int> > &matrix) {
    int i, j, n = matrix.size();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
    };
    vector<vector<int> > matrix(4, vector<int>(4));
    for (int i = 0; i < 4; i++) {
        matrix[i].assign(arr[i], arr[i] + 4);
    }
    rotate(matrix);
    printVV(matrix);
    return 0;
}
