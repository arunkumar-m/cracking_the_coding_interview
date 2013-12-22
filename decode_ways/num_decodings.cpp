/*
 * =====================================================================================
 *
 *       Filename:  num_decodings.cpp
 *
 *        Version:  1.0
 *        Created:  12/21/2013 17:13:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

void printArr(int *, int);

int numDecodings(string s) {
    if (s.length() == 0) return 0;
    int *D = new int[s.length() + 1];
    D[0] = 1;
    for (int i = 1; i <= s.length(); i++) {
        D[i] = 0;
        if (i >= 2 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
            D[i] += D[i - 2];
        }
        if (s[i - 1] != '0') {
            D[i] += D[i - 1];
        }
    }
    // printArr(D, s.length() + 1);
    return D[s.length()];
}

void printArr(int *D, int len) {
    for (int i = 0; i < len; i++) {
        cout << D[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << numDecodings("1012") << endl;
    return 0;
}
