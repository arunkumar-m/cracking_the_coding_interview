/*
 * =====================================================================================
 *
 *       Filename:  word_break_1d.cpp
 *
 *        Version:  1.0
 *        Created:  01/01/2014 13:34:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool wordBreak(string s, set<string> &dict) {
    int len = s.length();
    int *dp = new int[len + 1];
    dp[0] = 1;
    for (int i = 1; i <= len; i++) {
        dp[i] = 0;
    }
    for (int i = 1; i <= len; i++) {
        if (dict.find(s.substr(0, i)) != dict.end()) {
            dp[i] = 1;
        }
        else {
            for (int j = 1; j < i; j++) {
                // cout << "i: " << i << " j: " << j << ": " << dp[j] << " " << s.substr(j, i - j) << endl;
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
    return dp[len];
}

int main() {
    set<string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    cout << wordBreak("catsanddog", dict) << endl;
    return 0;
}
