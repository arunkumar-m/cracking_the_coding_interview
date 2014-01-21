/*
 * =====================================================================================
 *
 *       Filename:  removeRedundant.cpp
 *
 *        Version:  1.0
 *        Created:  01/20/2014 15:54:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

string removeRedundant(string str) {
    char ht[256] = {0};
    string ret = "";
    for (int i = 0; i < str.length(); i++) {
        ht[str[i]]++;
        if (ht[str[i]] == 1) {
            ret += str[i];
        }
    }
    return ret;
}

int main() {
    cout << removeRedundant("aabcddcd") << endl;
    cout << removeRedundant("12134354") << endl;
    cout << removeRedundant("1122334455") << endl;
    cout << removeRedundant("1234512345") << endl;
    cout << removeRedundant("56u4u5u1u3u") << endl;
    return 0;
}
