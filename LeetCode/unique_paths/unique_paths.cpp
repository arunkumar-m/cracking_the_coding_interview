/*
 * =====================================================================================
 *
 *       Filename:  unique_paths.cpp
 *
 *        Version:  1.0
 *        Created:  11/30/2013 23:00:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int uniquePaths(int m, int n) {
    if (!m || !n)
        return 0;
    // initialization
    int **dp = new int*[m];
    for (int i = 0; i < m; i++) {
        dp[i] = new int[n];
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    // dynamic programming
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main() {
    cout << uniquePaths(0, 1) << endl;
    cout << uniquePaths(1, 1) << endl;
    cout << uniquePaths(2, 2) << endl;
    cout << uniquePaths(3, 3) << endl;
    cout << uniquePaths(3, 7) << endl;
    return 0;
}
