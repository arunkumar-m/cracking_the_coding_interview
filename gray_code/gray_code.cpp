/*
 * =====================================================================================
 *
 *       Filename:  gray_code.cpp
 *
 *        Version:  1.0
 *        Created:  11/30/2013 21:14:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> grayCode(int n) {
    vector<int> result;
    if (n == 0) {
        result.push_back(0);
    }
    else if (n == 1) {
        result.push_back(0);
        result.push_back(1);
    }
    else {
        result = grayCode(n - 1);
        for (int i = 0; i < pow(2, n - 1); i++) {
            result.push_back(result[pow(2, n - 1) - 1 - i] + pow(2, n - 1));
        }
    }
    return result;
}

void printVec(vector<int> result) {
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> result = grayCode(0);
    printVec(result);
    result = grayCode(1);
    printVec(result);
    result = grayCode(2);
    printVec(result);
    result = grayCode(3);
    printVec(result);
    result = grayCode(4);
    printVec(result);
    result = grayCode(5);
    printVec(result);
    return 0;
}
