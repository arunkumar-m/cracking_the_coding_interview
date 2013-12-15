/*
 * =====================================================================================
 *
 *       Filename:  unique_paths_with_obstacles.cpp
 *
 *        Version:  1.0
 *        Created:  12/15/2013 15:28:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    // initialize
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int> > grid(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        if (obstacleGrid[0][i] != 1)
            grid[0][i] = 1;
        else
            break;
    }
    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] != 1)
            grid[i][0] = 1;
        else
            break;
    }

    // fill in the table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                grid[i][j] = 0;
            }
            else {
                grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
            }
        }
    }
    return grid[m - 1][n - 1];
}

int main() {
    int arr[3][3] = {
        {0,1,1},
        {0,1,0},
        {0,0,0},
    };
    vector<vector<int> > obstacleGrid(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        obstacleGrid[i].assign(arr[i], arr[i] + 3);
    }
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
