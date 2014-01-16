/*
 * =====================================================================================
 *
 *       Filename:  anagrams.cpp
 *
 *        Version:  1.0
 *        Created:  12/21/2013 23:19:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int partition(string &str, int begin, int end) {
    int pivotIndex = begin - 1;
    char pivotValue = str[end];
    for (int i = begin; i < end; i++) {
        if (str[i] < pivotValue) {
            swap(str[i], str[++pivotIndex]);
        }
    }
    swap(str[end], str[++pivotIndex]);
    return pivotIndex;
}

void quicksort(string &str, int begin, int end) {
    if (begin >= end) return;
    int pivotIndex = partition(str, begin, end);
    quicksort(str, begin, pivotIndex - 1);
    quicksort(str, pivotIndex + 1, end);
}

vector<vector<string> > anagrams(vector<string> &strs) {
    map<string, vector<string> > m;
    for (int i = 0; i < strs.size(); i++) {
        string str = strs[i];
        quicksort(str, 0, str.length() - 1);
        if (m.find(str) == m.end()) {
            vector<string> row;
            row.push_back(strs[i]);
            m[str] = row;
        }
        else {
            m[str].push_back(strs[i]);
        }
    }

    map<string, vector<string> >::iterator it;
    vector<vector<string> > results;
    for (it = m.begin(); it != m.end(); it++) {
        if (it->second.size() > 1) {
            vector<string> row;
            for (int i = 0; i < it->second.size(); i++) {
                row.push_back(it->second[i]);
            }
            results.push_back(row);
        }
    }
    return results;
}

void printVV(vector<vector<string> > &results) {
    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string arr[8] = {
        "asdf",
        "dsaf",
        "gasdf",
        "ssssf",
        "adsf",
        "fssss",
        "sfsss",
        "sfffs",
    };
    vector<string> strs(8);
    strs.assign(arr, arr + 8);
    vector<vector<string> > results = anagrams(strs);
    printVV(results);
    return 0;
}
