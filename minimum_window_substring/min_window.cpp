/*
 * =====================================================================================
 *
 *       Filename:  min_window.cpp
 *
 *        Version:  1.0
 *        Created:  12/31/2013 10:02:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

string minWindow(string S, string T) {
    int slen = S.length();
    int tlen = T.length();
    int hasFound[256] = {0};
    int needToFind[256] = {0};
    int minWindowBegin = 0, minWindowLen = INT_MAX;
    for (int i = 0; i < tlen; i++) {
        needToFind[T[i]]++;
    }
    int count = 0;
    for (int begin = 0, end = 0; end < slen; end++) {
        if (needToFind[S[end]] == 0) continue;
        if (hasFound[S[end]] < needToFind[S[end]]) count++;
        hasFound[S[end]]++;
        if (count == tlen) {
            while (needToFind[S[begin]] == 0 || hasFound[S[begin]] > needToFind[S[begin]]) {
                if (hasFound[S[begin]] > needToFind[S[begin]]) {
                    hasFound[S[begin]]--;
                }
                begin++;
            }
            int windowLen = end - begin + 1;
            if (windowLen < minWindowLen) {
                minWindowLen = windowLen;
                minWindowBegin = begin;
            }
        }
    }
    return minWindowLen == INT_MAX ? "" : S.substr(minWindowBegin, minWindowLen);
}

int main() {
    cout << minWindow("ABDOBECODEBANC", "ABC") << endl;
    return 0;
}
