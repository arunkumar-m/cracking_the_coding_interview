/*
 * =====================================================================================
 *
 *       Filename:  add_binary_simplified.cpp
 *
 *        Version:  1.0
 *        Created:  12/20/2013 10:41:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

string addBinary(string a, string b) {
    string result;
    int carry = 0;
    int length = max(a.length(), b.length());
    int m = a.length();
    int n = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < length; i++) {
        int x = (i < m) ? a[i] - '0' : 0;
        int y = (i < n) ? b[i] - '0' : 0;
        int val = (x + y + carry) % 2;
        carry = (x + y + carry) / 2;
        result.insert(result.begin(), val + '0');
    }
    if (carry == 1){
        result.insert(result.begin(), '1');
    }
    return result;
}

int main() {
    cout << addBinary("110", "11") << endl;
    return 0;
}
