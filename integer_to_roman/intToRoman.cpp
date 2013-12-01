/*
 * =====================================================================================
 *
 *       Filename:  intToRoman.cpp
 *
 *        Version:  1.0
 *        Created:  12/01/2013 01:08:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

string intToRoman(int num) {
    int d1 = num / 1000;
    int d2 = (num - d1 * 1000) / 100;
    int d3 = (num - d1 * 1000 - d2 * 100) / 10;
    int d4 = num % 10;
    string result = "";
    if (d1 > 0) {
        for (int i = 0; i < d1; i++) {
            result += "M";
        }
    }
    if (d2 > 0) {
        if (d2 == 9) {
            result += "CM";
        }
        else if (d2 == 4) {
            result += "CD";
        }
        else if (d2 >= 5) {
            result += "D";
            for (int i = 0; i < d2 - 5; i++) {
                result += "C";
            }
        }
        else if (d2 < 4) {
            for (int i = 0; i < d2; i++) {
                result += "C";
            }
        }
    }
    if (d3 > 0) {
        if (d3 == 9) {
            result += "XC";
        }
        else if (d3 == 4) {
            result += "XL";
        }
        else if (d3 >= 5) {
            result += "L";
            for (int i = 0; i < d3 - 5; i++) {
                result += "X";
            }
        }
        else if (d3 < 4) {
            for (int i = 0; i < d3; i++) {
                result += "X";
            }
        }
    }
    if (d4 > 0) {
        if (d4 == 9) {
            result += "IX";
        }
        else if (d4 == 4) {
            result += "IV";
        }
        else if (d4 >= 5) {
            result += "V";
            for (int i = 0; i < d4 - 5; i++) {
                result += "I";
            }
        }
        else if (d4 <= 4) {
            for (int i = 0; i < d4; i++) {
                result += "I";
            }
        }
    }
    return result;
}

int main() {
    cout << intToRoman(2013) << endl;
    cout << intToRoman(1990) << endl;
    cout << intToRoman(1954) << endl;
    return 0;
}
