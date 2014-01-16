/*
 * =====================================================================================
 *
 *       Filename:  combination_sum_2.cpp
 *
 *        Version:  1.0
 *        Created:  12/23/2013 11:06:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void printV(vector<int> &num);
void printVV(vector<vector<int> > &results);

int partition(vector<int> &num, int begin, int end) {
    int pivotIndex = begin - 1;
    int pivotValue = num[end];
    for (int i = begin; i < end; i++) {
        if (num[i] < pivotValue) {
            swap(num[i], num[++pivotIndex]);
        }
    }
    swap(num[end], num[++pivotIndex]);
    return pivotIndex;
}

void quicksort(vector<int> &num, int begin, int end) {
    if (begin >= end) return;
    int pivotIndex = partition(num, begin, end);
    quicksort(num, begin, pivotIndex - 1);
    quicksort(num, pivotIndex + 1, end);
}

vector<vector<int> > helper(vector<int> &num, int target) {
    vector<vector<int> > results;
    if (target < 0) {
        return results;
    }
    else if (target == 0) {
        vector<int> row;
        results.push_back(row);
        return results;
    }
    for (int i = 0; i < num.size(); i++) {
        if (target >= num[i]) {
            vector<int> n;
            n.assign(num.begin() + i + 1, num.end());
            vector<vector<int> > v = helper(n, target - num[i]);
            for (int j = 0; j < v.size(); j++) {
                v[j].insert(v[j].begin(), num[i]);
            }
            results.insert(results.end(), v.begin(), v.end());
        }
        else {
            break;
        }
    }
    return results;
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    quicksort(num, 0, num.size() - 1);
    vector<vector<int> > results = helper(num, target);
    set<vector<int> > s(results.begin(), results.end());
    results.assign(s.begin(), s.end());
    return results;
}

void printV(vector<int> &num) {
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << " ";
    }
    cout << endl;
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
    vector<int> num(7);
    int arr[] = {10,1,2,7,6,1,5};
    num.assign(arr, arr + 7);
    vector<vector<int> > results = combinationSum2(num, 8);
    printVV(results);
    return 0;
}
