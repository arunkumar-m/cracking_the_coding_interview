/*
 * =====================================================================================
 *
 *       Filename:  length_of_last_word.cpp
 *
 *        Version:  1.0
 *        Created:  12/15/2013 14:47:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int lengthOfLastWord(const char *s) {
    int len = 0, prev = 0;
    while (*s != '\0') {
        if (*s == ' ') {
            prev = len == 0 ? prev : len;
            len = 0;
        }
        else {
            len++;
        }
        s++;
    }
    return len == 0 ? prev : len;
}

int main() {
    char s[] = "helloworld asd a  ";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}
