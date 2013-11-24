# Word Break

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
    s = "leetcode",
    dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

## Solution

Dynamic programming.

Create a 2-D array _dp_, _dp[i][j]_ indicates if _s.substr(i, j-i+1)_ can
be segmented into a space-separated sequence of one or dictionary words.

_dp[i][j]_ is 1 if s.substr(i, j-i+1) can be found in _dict_ or
_dp[i][k] == 1 && dp[k][j] == 1_ for i <= k <= j. Otherwise, _dp[i][j]_
is 0.

The return value of the function _wordBreak_ is _dp[0][s.length()-1]_.
