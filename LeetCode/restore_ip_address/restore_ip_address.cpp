/*
 * =====================================================================================
 *
 *       Filename:  restore_ip_address.cpp
 *
 *        Version:  1.0
 *        Created:  12/23/2013 22:00:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void search(string s, vector<int> n, int curr, vector<string> &ret) {
    if (n.size() == 4 && curr >= s.length()) {
        string result;
        for (int i = 0; i < 3; i++) {
            char buffer[4];
            sprintf(buffer, "%d", n[i]);
            string s(buffer);
            result += s;
            result += '.';
        }
        char buffer[4];
        sprintf(buffer, "%d", n[3]);
        string s(buffer);
        result += s;
        ret.push_back(result);
    }
    if (curr < s.length()) {
        string str = s.substr(curr, 1);
        int num = atoi(str.c_str());
        if (num >= 0 && num <= 9) {
            vector<int> number(n.begin(), n.end());
            number.push_back(num);
            search(s, number, curr + 1, ret);
        }
        if (curr + 1 < s.length()) {
            str = s.substr(curr, 2);
            num = atoi(str.c_str());
            if (num >= 10 && num <= 99) {
                vector<int> number(n.begin(), n.end());
                number.push_back(num);
                search(s, number, curr + 2, ret);
            }
            if (curr + 2 < s.length()) {
                str = s.substr(curr, 3);
                num = atoi(str.c_str());
                if (num >= 100 && num <= 255) {
                    vector<int> number(n.begin(), n.end());
                    number.push_back(num);
                    search(s, number, curr + 3, ret);
                }
            }
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> ret;
    if (s.length() > 12) return ret;
    search(s, vector<int>(0), 0, ret);
    set<string> myset(ret.begin(), ret.end());
    ret.assign(myset.begin(), myset.end());
    return ret;
}

void printVector(vector<string> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

int main() {
    vector<string> ret = restoreIpAddresses("25525511135");
    printVector(ret);
    ret = restoreIpAddresses("0000");
    printVector(ret);
    ret = restoreIpAddresses("1111");
    printVector(ret);
    ret = restoreIpAddresses("010010");
    printVector(ret);
    return 0;
}
