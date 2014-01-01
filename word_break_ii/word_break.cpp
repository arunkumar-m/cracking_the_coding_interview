/*
 * =====================================================================================
 *
 *       Filename:  word_break.cpp
 *
 *        Version:  1.0
 *        Created:  01/01/2014 13:12:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <set>
#include <vector>
using namespace std;

void backtrack(int **dp, int index, string curr, string s, set<string> &dict, vector<string> &ret) {
    // cout << index << " " << curr << endl;
    int len = s.length();
    if (index >= len) {
        ret.push_back(curr);
        return;
    }
    string tmp = s.substr(index);
    if (dict.find(tmp) != dict.end()) {
        if (curr == "")
            ret.push_back(tmp);
        else if (curr[0] == ' ')
            ret.push_back(curr.substr(1) + " " + tmp);
        else
            ret.push_back(curr + " " + tmp);
    }
    for (int i = index; i < len - 1; i++) {
        if (dp[index][i] && dp[i + 1][len - 1]) {
            string tmp = s.substr(index, i - index + 1);
            if (dict.find(tmp) != dict.end()) {
                backtrack(dp, i + 1, curr + " " + tmp, s, dict, ret);
            }
        }
    }
}

vector<string> wordBreak(string s, set<string> &dict) {
    int len = s.length();
    int **dp = new int*[len];
    for (int i = 0; i < len; i++) {
        dp[i] = new int[len];
        for (int j = 0; j < len; j++) {
            dp[i][j] = 0;
        }
    }
    for (int j = 0; j < len; j++) {
        for (int i = j; i >= 0; i--) {
            if (dict.find(s.substr(i, j - i + 1)) != dict.end()) {
                dp[i][j] = 1;
            }
            else {
                for (int k = i; k < j; k++) {
                    if (dp[i][k] && dp[k + 1][j]) {
                        dp[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }
    // cout << dp[0][len - 1] << endl;
    vector<string> ret;
    if (!dp[0][len - 1]) return ret;
    backtrack(dp, 0, "", s, dict, ret);
    return ret;
}

void printVec(vector<string> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << "\"" << v[i] << "\", ";
    }
    cout << endl;
}

int main() {
    set<string> dict;
//    dict.insert("a");
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    vector<string> ret = wordBreak("catsanddog", dict);
//    vector<string> ret = wordBreak("a", dict);
    printVec(ret);
    return 0;
}
