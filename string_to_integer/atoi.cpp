/*
 * =====================================================================================
 *
 *       Filename:  atoi.cpp
 *
 *        Version:  1.0
 *        Created:  12/21/2013 22:48:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int atoi(const char *str) {
    while (*str != '\0' && *str == ' ') str++;
    if (*str == '\0') return 0;
    int minusSign = 1;
    if (*str == '-') {
        minusSign = -1;
        str++;
    }
    else if (*str == '+') {
        minusSign = 1;
        str++;
    }
    long long num = 0;
    while (*str != '\0') {
        if (*str <= '9' && *str >= '0') {
            num = num * 10 + (*str - '0');
            str++;
            if (minusSign == -1 && -num < INT_MIN) {
                return INT_MIN;
            }
            else if (minusSign == 1 && num > INT_MAX) {
                return INT_MAX;
            }
        }
        else {
            break;
        }
    }
    return minusSign * num;
}

int main() {
    cout << atoi("   2147483648") << endl;
    cout << atoi("   -0012a42") << endl;
    return 0;
}
