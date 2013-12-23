/*
 * =====================================================================================
 *
 *       Filename:  num_distinct.cpp
 *
 *        Version:  1.0
 *        Created:  12/22/2013 00:26:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

void printArr(int **A, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int numDistinct(string S, string T) {
    if (S.empty() || T.empty() || T.length() > S.length()) return 0;
    int m = S.length();
    int n = T.length();
    int **D = new int*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        D[i] = new int[m + 1];
        for (int j = 0; j < m + 1; j++) {
            D[i][j] = 0;
        }
    }
    for (int i = 0; i < m + 1; i++) {
        D[0][i] = 1;
    }
    for (int i = 1; i < n + 1; i++) {
        D[i][0] = 0;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            D[i][j] += D[i][j - 1];
            if (T[i - 1] == S[j - 1]) {
                D[i][j] += D[i - 1][j - 1];
            }
        }
    }
    return D[n][m];
}

int main() {
    cout << numDistinct("rabbbit", "rabbit") << endl;
    cout << numDistinct("", "a") << endl;
    cout << numDistinct("a", "") << endl;
    cout << numDistinct("b", "a") << endl;
    return 0;
}
