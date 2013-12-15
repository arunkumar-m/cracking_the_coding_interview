/*
 * =====================================================================================
 *
 *       Filename:  subsets_with_dup.cpp
 *
 *        Version:  1.0
 *        Created:  12/15/2013 13:02:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > results;
    if (S.size() == 1) {
        vector<int> tmp;
        results.push_back(tmp);
        tmp.push_back(S[0]);
        results.push_back(tmp);
        return results;
    }
    int first = S[0];
    S.erase(S.begin());
    vector<vector<int> > prev = subsets(S);
    for (int i = 0; i < prev.size(); i++) {
        vector<int> row = prev[i];
        results.push_back(row);
        row.push_back(first);
        results.push_back(row);

    }
    return results;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(vector<int> &vec, int left, int right) {
    swap(vec[left + (right - left) / 2], vec[right]);
    int pivotValue = vec[right];
    int pivotIndex = left - 1;
    for (int i = left; i < right; i++) {
        if (vec[i] > pivotValue) {
            pivotIndex++;
            swap(vec[pivotIndex], vec[i]);
        }
    }
    pivotIndex++;
    swap(vec[pivotIndex], vec[right]);
    return pivotIndex;
}

void quicksort(vector<int> &vec, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = partition(vec, left, right);
    quicksort(vec, left, pivotIndex - 1);
    quicksort(vec, pivotIndex + 1, right);
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    quicksort(S, 0, S.size() - 1);
    vector<vector<int> > results = subsets(S);
    set<vector<int> > tmp(results.begin(), results.end());
    results.assign(tmp.begin(), tmp.end());
    return results;
}

void printVV(vector<vector<int> > v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void printV(vector<int> v) {
    int i;
    for (i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[3] = {1,2,2};
    vector<int> S(3);
    S.assign(arr, arr + 3);
    vector<vector<int> > results = subsetsWithDup(S);
    printVV(results);
    return 0;
}
