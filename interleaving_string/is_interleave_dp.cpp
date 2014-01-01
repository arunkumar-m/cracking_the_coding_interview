/*
 * =====================================================================================
 *
 *       Filename:  is_interleave_dp.cpp
 *
 *        Version:  1.0
 *        Created:  01/01/2014 12:27:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();
    if (len1 + len2 != len3) return false;
    if (len3 == 0) return true;
    int **dp = new int*[len1 + 1];
    for (int i = 0; i <= len1; i++) {
        dp[i] = new int[len2 + 1];
        for (int j = 0; j <= len2; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= len1; i++) {
        if (dp[i - 1][0] == 1 && s1[i - 1] == s3[i - 1]) {
            dp[i][0] = 1;
        }
    }
    for (int i = 1; i <= len2; i++) {
        if (dp[0][i - 1] == 1 && s2[i - 1] == s3[i - 1]) {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if ((dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])) {
                dp[i][j] = 1;
            }
        }
    }
    return dp[len1][len2];
}

int main() {
    cout << isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    return 0;
}
