/*
 * =====================================================================================
 *
 *       Filename:  is_match.cpp
 *
 *        Version:  1.0
 *        Created:  01/02/2014 10:53:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

bool isMatch(const char *s, const char *p) {
    const char *star = NULL;
    const char *ss = s;
    while (*s) {
        if ((*p == '?') || (*p == *s)) {
            s++;
            p++;
        }
        else if (*p == '*') {
            star = p++;
            ss = s;
        }
        else if (star) {
            p = star + 1;
            s = ++ss;
        }
        else {
            return false;
        }
    }
    while (*p == '*') p++;
    return !*p;
}

int main() {
    cout << isMatch("aa", "a") << endl;
    cout << isMatch("aa", "aa") << endl;
    cout << isMatch("aaa", "aa") << endl;
    cout << isMatch("ab", "?*") << endl;
    cout << isMatch("aab", "c*a*b") << endl;
    cout << isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b") << endl;
    cout << isMatch("bbbbaaaaaaaabbabbaaaaaaabbaaaaaabbbbbbaabaabbaaababbabbbbbbbbbbabbaaaaaaabbbbbbababbaaabaaabbaaababbabbaaababaaababbaaaaaaabaaababbaaaabbbbabbbababaabaaaaaaaaaabbabbaaabbbbbabaabababbabbbabbaaababbaabab", "a****ba***b*b**aa*b*b**bbbab*aa*****a*a*bbb*aa*a*b*bab*b***b**abb*a*aab***b**a**b****b**a*a*aaa**aa*aba") << endl;
    cout << isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb") << endl;
    return 0;
}
