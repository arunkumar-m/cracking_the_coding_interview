/*
 * =====================================================================================
 *
 *       Filename:  equilibrium.cpp
 *
 *        Version:  1.0
 *        Created:  01/17/2014 01:59:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printVec(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printVecVec(const vector< vector<int> > &A) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int calcRow(const vector< vector<int> > &A, vector<int> &row) {
    int ssum = 0;
    for (int i = 0; i < A.size(); i++) {
        int sum = 0;
        for (int j = 0; j < A[0].size(); j++) {
            sum += A[i][j];
        }
        row[i] =sum;
        ssum += sum;
    }
    return ssum;
}

int calcCol(const vector< vector<int> > &A, vector<int> &col) {
    int ssum = 0;
    for (int i = 0; i < A[0].size(); i++) {
        int sum = 0;
        for (int j = 0; j < A.size(); j++) {
            sum += A[j][i];
        }
        col[i] = sum;
        ssum += sum;
    }
    return ssum;
}

int solution(const vector< vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<int> row(n);
    vector<int> col(m);
    int sum = calcRow(A, row);
    calcCol(A, col);
    int tmp = row[0];
    vector<int> isRowEq(n);
    vector<int> isColEq(n);
    for (int i = 1; i < n - 1; i++) {
        if (tmp == sum - row[i] - tmp) {
            isRowEq[i] = 1;
        }
        tmp += row[i];
    }
    tmp = col[0];
    for (int i = 1; i < m - 1; i++) {
        if (tmp == sum - col[i] - tmp) {
            isColEq[i] = 1;
        }
        tmp += col[i];
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (isColEq[j] == 1 && isRowEq[i] == 1) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    vector< vector<int> > A(5, vector<int>(3));
    A[0][0] = 2;
    A[0][1] = 7;
    A[0][2] = 5;
    A[1][0] = 3;
    A[1][1] = 1;
    A[1][2] = 1;
    A[2][0] = 2;
    A[2][1] = 1;
    A[2][2] = -7;
    A[3][0] = 0;
    A[3][1] = 2;
    A[3][2] = 1;
    A[4][0] = 1;
    A[4][1] = 6;
    A[4][2] = 8;
    cout << solution(A) << endl;
    return 0;
}
