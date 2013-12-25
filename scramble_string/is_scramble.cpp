/*
 * =====================================================================================
 *
 *       Filename:  is_scramble.cpp
 *
 *        Version:  1.0
 *        Created:  12/25/2013 09:25:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

bool isScramble(string s1, string s2) {
    int len = s1.length();
    if (len != s2.length()) return false;
    if (len == 0) return true;
    if (len == 1) return s1[0] == s2[0];
    if (len == 2) return (s1[0] == s2[0] && s1[1] == s2[1]) || (s1[0] == s2[1] && s2[0] == s1[1]);
    if (s1 == s2) return true;
    string ts1 = s1, ts2 = s2;
    sort(ts1.begin(), ts1.end());
    sort(ts2.begin(), ts2.end());
    if (ts1 != ts2) return false;
    for (int i = 1; i < len; i++) {
        string fst1 = s1.substr(0, i);
        string snd1 = s1.substr(i);
        string fst2 = s2.substr(0, i);
        string snd2 = s2.substr(i);
//        cout << fst1 << " " << fst2 << endl;
//        cout << snd1 << " " << snd2 << endl;
//        cout << "=== === === ===" << endl;
        if (isScramble(fst1, fst2) && isScramble(snd1, snd2)) return true;
    }
    for (int i = 0; i < len - 1; i++) {
        string fst3 = s1.substr(0, i + 1);
        string snd3 = s1.substr(i + 1);
        string fst4 = s2.substr(len - i - 1);
        string snd4 = s2.substr(0, len - i - 1);
//        cout << fst3 << " " << fst4 << endl;
//        cout << snd3 << " " << snd4 << endl;
//        cout << "=== === === ===" << endl;
        if (isScramble(fst3, fst4) && isScramble(snd3, snd4)) return true;
    }
    return false;
}

int main() {
    cout << isScramble("rgtae", "great") << endl;
    cout << isScramble("rgeat", "great") << endl;
    cout << isScramble("eargt", "great") << endl;
    cout << isScramble("abcdefghij", "efghijcadb") << endl;
    cout << isScramble("abc", "bac") << endl;
    cout << isScramble("abcdefghijklmn", "efghijklmncadb") << endl;
    return 0;
}
