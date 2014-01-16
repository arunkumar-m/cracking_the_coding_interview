/*
 * =====================================================================================
 *
 *       Filename:  num_decodings.cpp
 *
 *        Version:  1.0
 *        Created:  12/21/2013 16:56:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

void dfs(string s, int curr, int &cnt) {
    if (curr == s.length()) {
        cnt++;
        return;
    }
    if (s[curr] != '0') {
        dfs(s, curr + 1, cnt);
    }
    if (s[curr] == '1' && curr + 1 < s.length()) {
        dfs(s, curr + 2, cnt);
    }
    else if (s[curr] == '2' && curr + 1 < s.length() && s[curr + 1] < '7') {
        dfs(s, curr + 2, cnt);
    }
}

int numDecodings(string s) {
    int cnt = 0;
    dfs(s, 0, cnt);
    return cnt;
}

int main() {
    cout << numDecodings("1012") << endl;
    return 0;
}
