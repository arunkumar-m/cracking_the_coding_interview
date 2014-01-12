/*
 * =====================================================================================
 *
 *       Filename:  wis.cpp
 *
 *        Version:  1.0
 *        Created:  01/12/2014 14:54:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> wis(vector<int> &path) {
    int length = path.size();
    if (length < 1) return vector<int>();
    vector<int> A (length + 1);
    A[0] = 0;
    A[1] = path[0];
    for (int i = 2; i <= length; i++) {
        A[i] = max(A[i - 2] + path[i - 1], A[i - 1]);
    }
    return A;
}

vector<int> backtrack(vector<int> &path, vector<int> &A) {
    int length = path.size();
    vector<int> ret (length);
    int curr = length;
    while (curr > 0) {
        if (A[curr - 2] + path[curr - 1] > A[curr - 1]) {
            ret[curr - 1] = 1;
            curr -= 2;
        }
        else {
            curr -= 1;
        }
    }
    return ret;
}

void printVector(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> path;
    path.push_back(1);
    path.push_back(4);
    path.push_back(5);
    path.push_back(4);
    path.push_back(8);
    vector<int> A = wis(path);
    printVector(path);
    printVector(A);
    vector<int> B = backtrack(path, A);
    printVector(B);
    return 0;
}
