/*
 * =====================================================================================
 *
 *       Filename:  subsets.cpp
 *
 *        Version:  1.0
 *        Created:  12/05/2013 22:50:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> &num) {
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << " ";
    }
    cout << endl;
}

void printVV(vector<vector<int> > &num) {
    int i, j;
    for (i = 0; i < num.size(); i++) {
        for (j = 0; j < num[i].size(); j++) {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(vector<int> &num, int left, int right) {
    int pivotValue = num[(left + right) / 2];
    swap(num[(left + right) / 2], num[right]);
    int storeIndex = -1;
    for (int i = 0; i < right; i++) {
        if (num[i] < pivotValue) {
            storeIndex++;
            swap(num[storeIndex], num[i]);
        }
    }
    storeIndex++;
    swap(num[storeIndex], num[right]);
    return storeIndex;
}

void quicksort(vector<int> &num, int left, int right) {
    if (left >= right)
        return;
    int pivot = partition(num, left, right);
    quicksort(num, left, pivot-1);
    quicksort(num, pivot+1, right);
}

vector<vector<int> > generate_subsets(vector<int> S) {
    vector<vector<int> > result;
    if (S.size() == 0) {
        return result;
    }
    if (S.size() == 1) {
        vector<int> row;
        result.push_back(row);
        row.push_back(S[0]);
        result.push_back(row);
        return result;
    }
    int first = S[0];
    S.erase(S.begin());
    result = generate_subsets(S);
    int len = result.size();
    for (int i = 0; i < len; i++) {
        vector<int> row = result[i];
        row.insert(row.begin(), first);
        result.push_back(row);
    }
    return result;
}
vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > results;
    quicksort(S, 0, S.size() - 1);
    results = generate_subsets(S);
    return results;
}

int main() {
    int arr[10] = {1,4,3,2,8,6,9,10,7,5};
    vector<int> num(4);
    num.assign(arr, arr+4);
    vector<vector<int> > results = subsets(num);
    printVV(results);
    return 0;
}
