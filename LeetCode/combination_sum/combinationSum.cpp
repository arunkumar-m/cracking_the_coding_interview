/*
 * =====================================================================================
 *
 *       Filename:  combinationSum.cpp
 *
 *        Version:  1.0
 *        Created:  12/16/2013 15:55:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int partition(vector<int> &vec, int start, int end) {
    swap(vec[start + (end - start) / 2], vec[end]);
    int pivotValue = vec[end];
    int pivotIndex = start - 1;
    for (int i = start; i < end; i++) {
        if (vec[i] < pivotValue) {
            pivotIndex++;
            swap(vec[pivotIndex], vec[i]);
        }
    }
    pivotIndex++;
    swap(vec[end], vec[pivotIndex]);
    return pivotIndex;
}

void quicksort(vector<int> &vec, int start, int end) {
    if (start > end) {
        return;
    }
    int pivotIndex = partition(vec, start, end);
    quicksort(vec, start, pivotIndex - 1);
    quicksort(vec, pivotIndex + 1, end);
}

int sum(vector<int> &vec) {
    int s = 0;
    for (int i = 0; i < vec.size(); i++) {
        s += vec[i];
    }
    return s;
}

void combSum(vector<int> candidates, int target, vector<int> curr, int max_value, vector<vector<int> > &results) {
    if (target == 0) {
        results.push_back(curr);
        return;
    }
    for (int i = 0; i < candidates.size(); i++) {
        if (candidates[i] > target) {
            break;
        }
        else if (candidates[i] >= max_value) {
            vector<int> new_curr = curr;
            new_curr.push_back(candidates[i]);
            combSum(candidates, target - candidates[i], new_curr, max(max_value, candidates[i]), results);
        }
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    quicksort(candidates, 0, candidates.size() - 1);
    vector<vector<int> > results;
    combSum(candidates, target, vector<int>(), 0, results);
    return results;
}

void printV(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printVV(vector<vector<int> > v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> candidates(4);
    int arr[] = {2,3,6,7};
    candidates.assign(arr, arr + 4);
    vector<vector<int> > results = combinationSum(candidates, 7);
    printVV(results);
    return 0;
}
