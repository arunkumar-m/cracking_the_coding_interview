/*
 * =====================================================================================
 *
 *       Filename:  word_break.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/24/2013 01:39:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <set>
#include <string>
using namespace std;

bool wordBreak(string s, set<string> &dict) {
    int length = s.length();
    int i, j, k;
    set<string>::iterator it;

    // initialization
    int **dp = new int*[length];
    for (i = 0; i < length; i++) {
        dp[i] = new int[length];
        for (j = 0; j < length; j++) {
            dp[i][j] = 0;
        }
    }

    for (i = 0; i < length; i++) {
        for (j = length - 1; j >= 0; j--) {
            if (j > i)
                continue;
            // dp[j][i]
            string str = s.substr(j, i - j + 1);
            if (dict.find(str) != dict.end()) {
                dp[j][i] = 1;
            }
            else {
                for (k = j; k <= i; k++) {
                    if (dp[j][k] == 1 && dp[k+1][i] == 1) {
                        dp[j][i] = 1;
                        break;
                    }
                }
            }
        }
    }
    return dp[0][length-1] ? true : false;
}

int main() {
    set<string> dict;
    dict.insert("leet");
    dict.insert("code");
    cout << wordBreak("leetcode", dict) << endl;
    return 0;
}
