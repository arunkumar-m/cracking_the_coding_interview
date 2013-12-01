/*
 * =====================================================================================
 *
 *       Filename:  permutations.cpp
 *
 *        Version:  1.0
 *        Created:  12/01/2013 11:28:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > result;
    if (num.size() == 0) {
        return result;
    }
    if (num.size() == 1) {
        result.push_back(num);
        return result;
    }
    else {
        int x = num[0];
        num.erase(num.begin());
        vector<vector<int> > prev = permute(num);
        for (int i = 0; i < prev.size(); i++) {
            for (int j = 0; j <= prev[i].size(); j++) {
                vector<int> tmp = prev[i];
                tmp.insert(tmp.begin() + j, x);
                result.push_back(tmp);
            }
        }
        return result;
    }
}

void printVV(vector<vector<int> > result) {
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << "LENGTH: " << result.size() << endl;
}

int main() {
    vector<int> num(4, 0);
    int a[] = {1,2,3,4};
    num.assign(a, a + 4);
    vector<vector<int> > result = permute(num);
    printVV(result);
    return 0;
}
