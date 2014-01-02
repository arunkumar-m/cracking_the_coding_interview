/*
 * =====================================================================================
 *
 *       Filename:  is_match.cpp
 *
 *        Version:  1.0
 *        Created:  01/01/2014 15:57:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <stack>
using namespace std;

bool isMatch(const char *s, const char *p) {
    // base case
    if (*p == '\0') return *s == '\0';

    // next char is not '*: must match current character
    if (*(p + 1) != '*') {
        return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
    }

    // next char is '*'
    while ((*p == *s) || (*p == '.' && *s != '\0')) {
        if (isMatch(s, p + 2)) return true;
        s++;
    }

    return isMatch(s, p + 2);
}

int main() {
    cout << isMatch("aa", "a") << endl;
    cout << isMatch("aa", "aa") << endl;
    cout << isMatch("aaa", "aa") << endl;
    cout << isMatch("aa", "a*") << endl;
    cout << isMatch("aa", ".*") << endl;
    cout << isMatch("ab", ".*") << endl;
    cout << isMatch("aab", "c*a*b") << endl;
    cout << isMatch("ab", ".*c") << endl;
    cout << isMatch("aaa", "a*a") << endl;
    cout << isMatch("a", "ab*") << endl;
    cout << isMatch("bbbba", ".*a*a") << endl;
    return 0;
}
