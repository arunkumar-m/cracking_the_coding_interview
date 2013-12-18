/*
 * =====================================================================================
 *
 *       Filename:  permute_unique.cpp
 *
 *        Version:  1.0
 *        Created:  12/17/2013 14:16:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > results;
    if (num.size() == 1) {
        vector<int> row;
        row.push_back(num[0]);
        results.push_back(row);
        return results;
    }

    int first = num[0];
    num.erase(num.begin());
    vector<vector<int> > prev = permute(num);
    for (int i = 0; i < prev.size(); i++) {
        for (int j = 0; j <= prev[i].size(); j++) {
            vector<int> row = prev[i];
            row.insert(row.begin() + j, first);
            results.push_back(row);
        }
    }
    return results;
}

vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> > results = permute(num);
    set<vector<int> > s (results.begin(), results.end());
    results.assign(s.begin(), s.end());
    return results;
}

void printVV(vector<vector<int> > &results) {
    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {-1,-1,3,-1};
    vector<int> num;
    num.assign(arr, arr + 4);
    vector<vector<int> > results = permuteUnique(num);
    printVV(results);
    cout << "SIZE: " << results.size() << endl;
    return 0;
}
