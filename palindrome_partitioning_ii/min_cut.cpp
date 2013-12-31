/*
 * =====================================================================================
 *
 *       Filename:  min_cut.cpp
 *
 *        Version:  1.0
 *        Created:  12/30/2013 22:17:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

int minCut(string s) {
    int len = s.length();
    if (len <= 1) return 0;
    vector<vector<bool> > dp(len, vector<bool>(len));
    for (int i = 0; i < len; i++) {
        dp[i].assign(len, false);
    }
    for (int i = 0; i < len; i++) {
        dp[i][i] = true;
    }
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i+1] = true;
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (j < i && i - 1 >= 0 && j + 1 < len && s[i] == s[j] && dp[j + 1][i - 1] == true) {
                dp[j][i] = true;
            }
        }
    }
    vector<int> d(len + 1);
    for (int i = 0; i <= len; i++) {
        d[i] = len - i - 1;
    }
    for (int i = len - 1; i >= 0; i--) {
        for (int j = i; j < len; j++) {
            if (dp[i][j]) {
                d[i] = min(d[i], 1 + d[j + 1]);
            }
        }
    }
    return d[0];
}

int main() {
    cout << minCut("aab") << endl;
    cout << minCut("aaabbaaa") << endl;
    cout << minCut("aabbbaaa") << endl;
    return 0;
}
