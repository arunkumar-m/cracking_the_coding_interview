/*
 * =====================================================================================
 *
 *       Filename:  is_interleave.cpp
 *
 *        Version:  1.0
 *        Created:  01/01/2014 10:04:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

class Solution {
    public:
        string str1, str2, str3;

        bool check(int p1, int q1, int p2, int q2, int p3, int q3) {
            if (p3 > q3) return true;
            if (p1 > q1) {
                for ( ; p2 <= q2 && p3 <= q3; p2++, p3++) {
                    if (str2[p2] != str3[p3]) return false;
                }
                return true;
            }
            if (p2 > q2) {
                for ( ; p1 <= q1 && p3 <= q3; p1++, p3++) {
                    if (str1[p1] != str3[p3]) return false;
                }
                return true;
            }
            if (str1[p1] == str3[p3]) {
                if (str1[q1] == str3[q3] && check(p1 + 1, q1 - 1, p2, q2, p3 + 1, q3 - 1)) return true;
                if (str2[q2] == str3[q3] && check(p1 + 1, q1, p2, q2 - 1, p3 + 1, q3 - 1)) return true;
            }
            if (str2[p2] == str3[p3]) {
                if (str1[q1] == str3[q3] && check(p1, q1 - 1, p2 + 1, q2, p3 + 1, q3 - 1)) return true;
                if (str2[q2] == str3[q3] && check(p1, q1, p2 + 1, q2 - 1, p3 + 1, q3 - 1)) return true;
            }
            return false;
        }

        bool isInterleave(string s1, string s2, string s3) {
            if (s1.length() + s2.length() != s3.length()) return false;
            str1 = s1;
            str2 = s2;
            str3 = s3;
            return check(0, s1.length() - 1, 0, s2.length() - 1, 0, s3.length() - 1);
        }
};

int main() {
    Solution s;
    string s1 = "abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb";
    string s2 = "ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc";
    string s3 = "cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc";
    cout << s.isInterleave(s1, s2, s3) << endl;
    return 0;
}
