/*
 * =====================================================================================
 *
 *       Filename:  generate_matrix.cpp
 *
 *        Version:  1.0
 *        Created:  12/04/2013 20:07:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

void moveRight(vector<vector<int> > &result, int &i, int &j, int &element) {
    int n = result.size();
    for ( ; j+1 < n; j++) {
        if (result[i][j+1] == 0) {
            result[i][j+1] = ++element;
        }
        else {
            break;
        }
    }
}

void moveDown(vector<vector<int> > &result, int &i, int &j, int &element) {
    int n = result.size();
    for ( ; i+1 < n; i++) {
        if (result[i+1][j] == 0) {
            result[i+1][j] = ++element;
        }
        else {
            break;
        }
    }
}

void moveLeft(vector<vector<int> > &result, int &i, int &j, int &element) {
    int n = result.size();
    for ( ; j-1 >= 0; j--) {
        if (result[i][j-1] == 0) {
            result[i][j-1] = ++element;
        }
        else {
            break;
        }
    }
}

void moveUp(vector<vector<int> > &result, int &i, int &j, int &element) {
    int n = result.size();
    for ( ; i-1 >= 0; i--) {
        if (result[i-1][j] == 0) {
            result[i-1][j] = ++element;
        }
        else {
            break;
        }
    }
}

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > result;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            row.push_back(0);
        }
        result.push_back(row);
    }

    int i = 0, j = -1, element = 0;

    for (int k = 0; k <= n / 2; k++) {
        moveRight(result, i, j, element);
        moveDown(result, i, j, element);
        moveLeft(result, i, j, element);
        moveUp(result, i, j, element);
    }
    return result;
}

void printVV(vector<vector<int> > matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int> > matrix;
    matrix = generateMatrix(10);
    printVV(matrix);
    return 0;
}
