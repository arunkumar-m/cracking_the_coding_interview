/*
 * =====================================================================================
 *
 *       Filename:  convert.cpp
 *
 *        Version:  1.0
 *        Created:  12/24/2013 09:56:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

string convert(string s, int nRows) {
    if (s.length() <= nRows || nRows == 1) return s;
    string *strs = new string[nRows];
    for (int i = 0; i < nRows; i++) {
        strs[i] = "";
    }
    int i = 0;
    int down = 1;
    int row = 0;
    while (i < s.length()) {
        strs[row] += s[i];
        if (down) {
            row++;
            if (row == nRows) {
                row -= 2;
                down = 0;
            }
        }
        else {
            row--;
            if (row == -1) {
                row = 1;
                down = 1;
            }
        }
        i++;
    }
    string ret = "";
    for (int i = 0; i < nRows; i++) {
        ret += strs[i];
    }
    delete[] strs;
    return ret;
}

int main() {
    string s = "resultpaypalsuper";
    cout << convert(s, 4) << endl;
    cout << convert("ABC", 2) << endl;
    return 0;
}
