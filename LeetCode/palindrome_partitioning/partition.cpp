/*
 * =====================================================================================
 *
 *       Filename:  partition.cpp
 *
 *        Version:  1.0
 *        Created:  12/20/2013 22:07:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

void print2DVec(vector<vector<bool> > &dp) {
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void findPartition(int index, vector<string> curr, vector<vector<string> > &results, vector<vector<bool> > &dp, string s) {
    int len = dp.size();
    if (index >= len) {
        results.push_back(curr);
        return;
    }
    for (int i = 0; i < len; i++) {
        if (dp[index][i] == true) {
            vector<string> tmp = curr;
            tmp.push_back(s.substr(index, i - index + 1));
            findPartition(i + 1, tmp, results, dp, s);
        }
    }
}

vector<vector<string> > partition(string s) {
    int len = s.length();
    // init
    vector<vector<bool> > dp(len, vector<bool>(len));
    for (int i = 0; i < len; i++) {
        dp[i].assign(len, false);
    }
    for (int i = 0; i < len; i++) {
        dp[i][i] = true;
    }
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
        }
    }

    // fill in the table
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (j < i && i - 1 >= 0 && j + 1 < len && dp[j + 1][i - 1] == true && s[j] == s[i]) {
                dp[j][i] = true;
            }
        }
    }

    // find palindrome partition
    vector<vector<string> > results;
    findPartition(0, vector<string>(), results, dp, s);

    return results;
}

int main() {
    string s = "aab";
    vector<vector<string> > results = partition(s);
    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
