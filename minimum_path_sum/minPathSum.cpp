/*
 * =====================================================================================
 *
 *       Filename:  minPathSum.cpp
 *
 *        Version:  1.0
 *        Created:  11/30/2013 21:53:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int> > &grid) {
    // initialization
    int m = grid.size();
    if (m == 0) {
        return 0;
    }
    int n = grid[0].size();
    if (n == 0) {
        return 0;
    }
    vector<vector<int> > dp = grid;
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n; ++i) {
        dp[0][i] += dp[0][i - 1];
    }
    for (int i = 1; i < m; ++i) {
        dp[i][0] += dp[i - 1][0];
    }
    // dynamic programming
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    vector<vector<int> > grid(2, vector<int>(3));
    int arr[2][3] = {
        {1,2,5},
        {3,2,1},
    };
    for (int i = 0; i < 2; i++) {
        grid[i].assign(arr[i], arr[i] + 3);
    }
    cout << minPathSum(grid) << endl;
    return 0;
}
