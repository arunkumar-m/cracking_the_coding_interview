# Wildcard Matching

Implement wildcard pattern matching with support for '?' and '*'.

    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).

    The matching should cover the entire input string (not partial).

    The function prototype should be:
    bool isMatch(const char *s, const char *p)

    Some examples:
    isMatch("aa","a") → false
    isMatch("aa","aa") → true
    isMatch("aaa","aa") → false
    isMatch("aa", "*") → true
    isMatch("aa", "a*") → true
    isMatch("ab", "?*") → true
    isMatch("aab", "c*a*b") → false

## Solution

Using recursion can not pass large test. Try dynamic programming but run
into memory limit exceeded error.

    int slen = strlen(s);
    int plen = strlen(p);
    // init
    int **dp = new int*[slen + 1];
    for (int i = 0; i <= slen; i++) {
        dp[i] = new int[plen + 1];
        for (int j = 0; j <= plen; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= plen; i++) {
        if (*(p + i - 1) == '*' && dp[0][i - 1]) {
            dp[0][i] = 1;
        }
    }
    // fill in the table
    for (int i = 1; i <= slen; i++) {
        for (int j = 1; j <= plen; j++) {
            if (*(p + j - 1) == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (*(p + j - 1) == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1] || dp[i][j - 1];
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] && *(p + j - 1) == *(s + i - 1);
            }
        }
    }
    return dp[slen][plen];

Use greedy algorithm to solve it instead. Very tricky.
