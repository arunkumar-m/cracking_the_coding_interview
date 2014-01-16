/*
 * =====================================================================================
 *
 *       Filename:  roman_to_integer.cpp
 *
 *        Version:  1.0
 *        Created:  11/30/2013 13:33:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

void r2i(string s, int &result) {
    // cout << s << " " << result << endl;
    int length = s.length();
    if (length == 0)
        return;
    else if (length == 1) {
        switch (s[0])
        {
            case 'I':
                result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                result += 10;
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                result += 100;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
        }
    }
    else {
        switch (s[0])
        {
            case 'I':
                if (s[1] == 'V') {
                    result += 4;
                    r2i(s.substr(2, length - 2), result);
                }
                else if (s[1] == 'X') {
                    result += 9;
                    r2i(s.substr(2, length - 2), result);
                }
                else {
                    result += 1;
                    r2i(s.substr(1, length - 1), result);
                }
                break;
            case 'V':
                result += 5;
                r2i(s.substr(1, length - 1), result);
                break;
            case 'X':
                if (s[1] == 'L') {
                    result += 40;
                    r2i(s.substr(2, length - 2), result);
                }
                else if (s[1] == 'C') {
                    result += 90;
                    r2i(s.substr(2, length - 2), result);
                }
                else {
                    result += 10;
                    r2i(s.substr(1, length - 1), result);
                }
                break;
            case 'L':
                result += 50;
                r2i(s.substr(1, length - 1), result);
                break;
            case 'C':
                if (s[1] == 'D') {
                    result += 400;
                    r2i(s.substr(2, length - 2), result);
                }
                else if (s[1] == 'M') {
                    result += 900;
                    r2i(s.substr(2, length - 2), result);
                }
                else {
                    result += 100;
                    r2i(s.substr(1, length - 1), result);
                }
                break;
            case 'D':
                result += 500;
                r2i(s.substr(1, length - 1), result);
                break;
            case 'M':
                result += 1000;
                r2i(s.substr(1, length - 1), result);
                break;
        }
    }
}

int romanToInt(string s) {
    int result = 0;
    r2i(s, result);
    return result;
}

int main() {
    // cout << romanToInt("MCMLIV") << endl;
    // cout << romanToInt("MCMXC") << endl;
    // cout << romanToInt("MMXIII") << endl;
    cout << romanToInt("MMMCC") << endl;
    return 0;
}
