/*
 * =====================================================================================
 *
 *       Filename:  add_binary.cpp
 *
 *        Version:  1.0
 *        Created:  12/20/2013 10:09:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

void reverse(string &str) {
    int begin = 0;
    int end = str.length() - 1;
    while (begin < end) {
        char tmp = str[begin];
        str[begin] = str[end];
        str[end] = tmp;
        begin++;
        end--;
    }
}

string addBinary(string a, string b) {
    string result;
    int m = a.length() - 1;
    int n = b.length() - 1;
    if (m > n) {
        b.insert(0, m - n, '0');
    }
    else if (m < n) {
        a.insert(0, n - m, '0');
    }
    m = n = max(m, n);
    int carry = 0;
    while (1) {
        if (m >= 0 && n >= 0) {
            char x = a[m];
            char y = b[n];
            if (carry == 0) {
                if (x != y) {
                    result.append(1, '1');
                    carry = 0;
                }
                else {
                    if (x == '1') {
                        carry = 1;
                    }
                    else {
                        carry = 0;
                    }
                    result.append(1, '0');
                }
            }
            else {
                if (x != y) {
                    result.append(1, '0');
                    carry = 1;
                }
                else {
                    if (x == '0') {
                        carry = 0;
                    }
                    else {
                        carry = 1;
                    }
                    result.append(1, '1');
                }
            }

            m--;
            n--;
        }
        else {
            break;
        }
    }
    if (carry == 1) {
        result.append(1, '1');
    }
    reverse(result);
    return result;
}

int main() {
    string result = addBinary("111", "1");
    cout << result << endl;
    return 0;
}
