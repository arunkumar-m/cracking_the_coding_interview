/*
 * =====================================================================================
 *
 *       Filename:  generate.cpp
 *
 *        Version:  1.0
 *        Created:  11/30/2013 14:09:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > result;
    if (numRows > 0) {
        vector<int> row;
        row.push_back(1);
        result.push_back(row);
    }
    for (int i = 1; i < numRows; i++) {
        vector<int> row;
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i)
                row.push_back(1);
            else {
                row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
        }
        result.push_back(row);
    }
    return result;
}

void printVV(vector<vector<int> > result) {
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int> > result = generate(5);
    printVV(result);
    return 0;
}
