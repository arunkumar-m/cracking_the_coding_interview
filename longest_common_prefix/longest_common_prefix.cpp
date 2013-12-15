/*
 * =====================================================================================
 *
 *       Filename:  longest_common_prefix.cpp
 *
 *        Version:  1.0
 *        Created:  12/15/2013 14:31:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() < 1)
        return "";
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        int cnt = 0, j = 0;
        while (j < strs[i].length() && j < prefix.length() && strs[i][j] == prefix[j]) {
            cnt++;
            j++;
        }
        prefix = prefix.substr(0, cnt);
    }
    return prefix;
}

int main() {
    vector<string> strs;
    strs.push_back("hello1");
    strs.push_back("hello11234");
    strs.push_back("hello2131");
    strs.push_back("hello41231");
    strs.push_back("hello501231");
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}
