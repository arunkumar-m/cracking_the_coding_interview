/*
 * =====================================================================================
 *
 *       Filename:  spiral_matrix.cpp
 *
 *        Version:  1.0
 *        Created:  01/26/2014 01:46:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int> > &mat, int x, int y, int width, int height) {
    if (width <= 0 || height <= 0) return;
    if (width == 1) {
        for (int i = x; i < x + height; i++) {
            cout << mat[i][y] << " ";
        }
        return;
    }
    if (height == 1) {
        for (int i = y; i < y + width; i++) {
            cout << mat[x][i] << " ";
        }
        return;
    }
    // go right
    for (int i = y; i < y + width; i++) {
        cout << mat[x][i] << " ";
    }
    // go down
    for (int i = x + 1; i < x + height; i++) {
        cout << mat[i][y + width - 1] << " ";
    }
    // go left
    for (int i = y + width - 2; i >= y; i--) {
        cout << mat[x + height - 1][i] << " ";
    }
    // go up
    for (int i = x + height - 2; i > x; i--) {
        cout << mat[i][y] << " ";
    }

    helper(mat, x + 1, y + 1, width - 2, height - 2);
}

void print_spiral_matrix(vector<vector<int> > &mat) {
    int height = mat.size();
    int width = height ? mat[0].size() : 0;
    cout << "width: " << width << " height: " << height << endl;
    if (!height || !width) return;
    helper(mat, 0, 0, width, height);
    cout << endl;
}

int main() {
    vector<vector<int> > mat(2, vector<int>(3));
    int cnt = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] = cnt++;
        }
    }
    print_spiral_matrix(mat);
    return 0;
}
