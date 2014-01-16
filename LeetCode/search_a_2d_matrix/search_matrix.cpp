/*
 * =====================================================================================
 *
 *       Filename:  search_matrix.cpp
 *
 *        Version:  1.0
 *        Created:  12/02/2013 01:05:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0, high = m, mid;
    while (low + 1 < high) {
        mid = low + (high - low) / 2;
        if (matrix[mid][0] == target) {
            return true;
        }
        else if (matrix[mid][0] < target) {
            low = mid;
        }
        else if (matrix[mid][0] > target) {
            high = mid;
        }
    }
    int row = low;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (matrix[row][mid] == target) {
            return true;
        }
        else if (matrix[row][mid] < target) {
            low = mid + 1;
        }
        else if (matrix[row][mid] > target) {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    int arr[3][4] = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,50},
    };
    vector<vector<int> > matrix(3, vector<int>(4));
    for (int i = 0; i < 3; i++) {
        matrix[i].assign(arr[i], arr[i] + 4);
    }
    cout << "0: " << searchMatrix(matrix, 0) << endl;
    cout << "3: " << searchMatrix(matrix, 3) << endl;
    cout << "11: " << searchMatrix(matrix, 11) << endl;
    cout << "30: " << searchMatrix(matrix, 30) << endl;
    cout << "55: " << searchMatrix(matrix, 55) << endl;
    matrix.clear();
    matrix.push_back(vector<int>(1, 1));
    cout << "0: " << searchMatrix(matrix, 0) << endl;
    cout << "1: " << searchMatrix(matrix, 1) << endl;
    return 0;
}
