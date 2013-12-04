/*
 * =====================================================================================
 *
 *       Filename:  get_row.cpp
 *
 *        Version:  1.0
 *        Created:  12/03/2013 22:04:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

int Cnr(int n, int r) {
    if (r > n) return 0;
    if (r * 2 > n) r = n - r;
    
    long long result = 1;
    for (int i = 1; i <= r; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

vector<int> getRow(int rowIndex) {
    vector<int> result;
    for (int i = 0; i <= rowIndex; i++) {
        result.push_back(Cnr(rowIndex, i));
    }
    return result;
}

void printV(vector<int> result) {
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> result = getRow(30);
    printV(result);
    return 0;
}
