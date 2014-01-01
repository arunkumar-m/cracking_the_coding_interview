/*
 * =====================================================================================
 *
 *       Filename:  multiply.cpp
 *
 *        Version:  1.0
 *        Created:  12/31/2013 16:37:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

string add(string num1, string num2) {
    string ret = "";
    int len1 = num1.length(), len2 = num2.length();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int carry = 0, sum = 0;
    for (int i = 0; i < max(len1, len2); i++) {
        int a = i < len1 ? num1[i] - '0' : 0;
        int b = i < len2 ? num2[i] - '0' : 0;
        sum = (carry + a + b) % 10;
        carry = (carry + a + b) / 10;
        ret.insert(ret.begin(), 1, sum + '0');
    }
    if (carry == 1) {
        ret.insert(ret.begin(), 1, '1');
    }
    return ret;
}

string mult(string num1, char digit) {
    int b = digit - '0';
    if (b == 0) return "0";
    string ret = "";
    int len = num1.length();
    reverse(num1.begin(), num1.end());
    int carry = 0;
    for (int i = 0; i < len; i++) {
        int a = num1[i] - '0';
        int tmp = (a * b + carry) % 10;
        carry = (a * b + carry) / 10;
        ret.insert(ret.begin(), 1, tmp + '0');
    }
    if (carry > 0) {
        ret.insert(ret.begin(), 1, carry + '0');
    }
    return ret;
}

string multiply(string num1, string num2) {
    string ret = "0";
    for (int i = num2.length() - 1, j = 0; i >= 0; i--, j++) {
        // cout << num1 << "*" << num2[i] << endl;
        string tmp = mult(num1, num2[i]);
        tmp.append(j, '0');
        // cout << ret << "+" << tmp << endl;
        ret = add(ret, tmp);
    }
    // remove zeros
    int i = 0;
    while (i < ret.length() - 1) {
        if (ret[i] == '0') {
            ret.erase(i, 1);
        }
        else {
            break;
        }
    }
    return ret;
}

int main() {
    cout << add("99", "10") << endl;
    cout << mult("212", '0') << endl;
    cout << mult("19", '9') << endl;
    cout << multiply("212", "19") << endl;
    cout << multiply("212", "0") << endl;
    return 0;
}
