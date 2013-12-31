/*
 * =====================================================================================
 *
 *       Filename:  spiral_order.cpp
 *
 *        Version:  1.0
 *        Created:  12/31/2013 11:28:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

void spiral(vector<vector<int> > &matrix, int m, int n, int k, vector<int> &results) {
    if (m - 2 * k <= 0 || n - 2 * k <= 0) return;

    if (m - 2 * k == 1) {
        for (int i = k; i < n - k; i++) {
            results.push_back(matrix[k][i]);
        }
        return;
    }

    if (n - 2 * k == 1) {
        for (int i = k; i < m - k; i++) {
            results.push_back(matrix[i][k]);
        }
        return;
    }

    // right
    for (int i = k; i < n - k; i++) {
        results.push_back(matrix[k][i]);
    }
    // down
    for (int i = k + 1; i < m - k; i++) {
        results.push_back(matrix[i][n - k - 1]);
    }
    // left
    for (int i = n - k - 2; i >= k; i--) {
        results.push_back(matrix[m - k - 1][i]);
    }
    // up
    for (int i = m - k - 2; i > k; i--) {
        results.push_back(matrix[i][k]);
    }

    spiral(matrix, m, n, k + 1, results);
}

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    int m = matrix.size();
    int n = m == 0 ? 0 : matrix[0].size();
    vector<int> results;
    spiral(matrix, m, n, 0, results);
    return results;
}

void printVector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> results;
    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    vector<vector<int> > matrix(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        matrix[i].assign(arr[i], arr[i] + 3);
    }
    results = spiralOrder(matrix);
    printVector(results);
    vector<vector<int> > matrix1(1, vector<int>(2));
    matrix1[0][0] = 2;
    matrix1[0][1] = 3;
    results = spiralOrder(matrix1);
    printVector(results);
    vector<vector<int> > matrix2(2, vector<int>(3));
    matrix2[0][0] = 2;
    matrix2[0][1] = 5;
    matrix2[0][2] = 8;
    matrix2[1][0] = 4;
    matrix2[1][1] = 0;
    matrix2[1][2] = -1;
    results = spiralOrder(matrix2);
    printVector(results);
    return 0;
}
