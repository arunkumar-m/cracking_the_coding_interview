/*
 * =====================================================================================
 *
 *       Filename:  find_substring.cpp
 *
 *        Version:  1.0
 *        Created:  12/31/2013 17:42:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> result;
    int len = S.length(), llen = L.size();
    int wordLen = L[0].length();
    map<string, int> needToFind;
    for (int i = 0; i < L.size(); i++) {
        needToFind[L[i]]++;
    }

    int i = 0;
    while (i + wordLen * llen <= len) {
        map<string, int> hasFound;
        int j = 0;
        while (j < llen) {
            string str = S.substr(i + j * wordLen, wordLen);
            if (needToFind.find(str) == needToFind.end()) {
                break;
            }
            else {
                hasFound[str]++;
                if (hasFound[str] > needToFind[str]) {
                    break;
                }
                j++;
            }
        }
        if (j == llen) {
            result.push_back(i);
        }
        i++;
    }
    return result;
}

void printVec(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<string> L;
    L.push_back("foo");
    L.push_back("bar");
    vector<int> result = findSubstring("barfoothefoobarman", L);
    printVec(result);
    L.clear();
    L.push_back("a");
    L.push_back("a");
    result = findSubstring("aaa", L);
    printVec(result);
    return 0;
}
