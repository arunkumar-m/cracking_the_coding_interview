/*
 * =====================================================================================
 *
 *       Filename:  is_number.cpp
 *
 *        Version:  1.0
 *        Created:  01/03/2014 17:54:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

bool isNumber(const char *s) {
    enum inputType {
        INVALID, // 0
        SPACE, // 1
        SIGN, // 2
        DIGIT, // 3
        DOT, // 4
        EXPONENT, // 5
        NUM_INPUTS // 6
    };
    int transitionTable[][NUM_INPUTS] = {
        -1,  0,  3,  1,  2, -1, // next state for state 0
        -1,  8, -1,  1,  4,  5, // next state for state 1
        -1, -1, -1,  4, -1, -1, // next state for state 2
        -1, -1, -1,  1,  2, -1, // next state for state 3
        -1,  8, -1,  4, -1,  5, // next state for state 4
        -1, -1,  6,  7, -1, -1, // next state for state 5
        -1, -1, -1,  7, -1, -1, // next state for state 6
        -1,  8, -1,  7, -1, -1, // next state for state 7
        -1,  8, -1, -1, -1, -1, // next state for state 8
    };
    int state = 0;
    while (*s != '\0') {
       inputType t = INVALID;
       if (isspace(*s))
           t = SPACE;
       else if (*s == '+' || *s == '-')
           t = SIGN;
       else if (isdigit(*s))
           t = DIGIT;
       else if (*s == '.')
           t = DOT;
       else if (*s == 'e' || *s == 'E')
           t = EXPONENT;

       state = transitionTable[state][t];

       if (state == -1) return false;
       else s++;
    }

    return state == 1 || state == 4 || state == 7 || state == 8;
}

int main() {
    cout << isNumber("0") << endl;
    cout << isNumber(" 0.1 ") << endl;
    cout << isNumber("abc") << endl;
    cout << isNumber("1 a") << endl;
    cout << isNumber("2e10") << endl;
    return 0;
}
