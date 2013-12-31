/*
 * =====================================================================================
 *
 *       Filename:  maximal_rectangle.cpp
 *
 *        Version:  1.0
 *        Created:  12/30/2013 14:03:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxHistArea(int *height, int len) {
    stack<int> s;
    int maxArea = 0;
    int i = 0;
    while (i < len) {
        if (s.empty() || height[s.top()] <= height[i]) {
            s.push(i++);
        }
        else {
            int t = s.top();
            s.pop();
            maxArea = max(maxArea, height[t] * (s.empty() ? i : i - s.top() - 1));
        }
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char> > &matrix) {
    int m = matrix.size();
    int n = m == 0 ? 0 : matrix[0].size();
    int **height = new int*[m];
    for (int i = 0; i < m; i++) {
        height[i] = new int[n + 1];
        height[i][n] = 0;
    }
    int maxArea = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '0') {
                height[i][j] = 0;
            }
            else {
                height[i][j] = i == 0 ? 1 : height[i - 1][j] + 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        maxArea = max(maxArea, maxHistArea(height[i], n + 1));
    }
    return maxArea;
}

int main() {
    char c[3][5] = {
        {'0','1','1','1','0'},
        {'0','1','1','1','1'},
        {'0','0','1','0','1'},
    };
    vector<vector<char> > matrix(3, vector<char>(5));
    for (int i = 0; i < 3; i++) {
        matrix[i].assign(c[i], c[i] + 5);
    }
    cout << maximalRectangle(matrix) << endl;
    char c1[1][7] = {{'1','0','1','0','0','1','1'}};
    vector<vector<char> > matrix1(1, vector<char>(7));
    for (int i = 0; i < 1; i++) {
        matrix1[i].assign(c1[i], c1[i] + 7);
    }
    cout << maximalRectangle(matrix1) << endl;
    return 0;
}
