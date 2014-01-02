# Regular Expression Matching

Implement regular expression matching with support for '.' and '*'.

    '.' Matches any single character.
    '*' Matches zero or more of the preceding element.

    The matching should cover the entire input string (not partial).

    The function prototype should be:
    bool isMatch(const char *s, const char *p)

    Some examples:
    isMatch("aa","a") → false
    isMatch("aa","aa") → true
    isMatch("aaa","aa") → false
    isMatch("aa", "a*") → true
    isMatch("aa", ".*") → true
    isMatch("ab", ".*") → true
    isMatch("aab", "c*a*b") → true

## Solution

The [solution](http://leetcode.com/2011/09/regular-expression-matching.html) posted on LeetCode is really simple and elegant.

There are two cases that we need to handle:
- If next char is not '*', we must match current character
- If next char is '*', then we have to do a brute force exhaustive matching of 0, 1, or more repeats of current character of p ... until we could not match any more characters
