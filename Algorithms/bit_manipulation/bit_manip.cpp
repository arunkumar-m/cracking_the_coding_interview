/*
 * =====================================================================================
 *
 *       Filename:  sign_of_int.cpp
 *
 *        Version:  1.0
 *        Created:  01/20/2014 00:13:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int main() {
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    cout << "##### ##### ##### ##### Bit Manipulation! ##### ##### ##### #####" << endl;
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    cout << "##### ##### ##### #####     Reference     ##### ##### ##### #####" << endl;
    cout << "##### ##### ##### ##### ===== ===== ===== ##### ##### ##### #####" << endl;
    cout << "#####  http://graphics.stanford.edu/~seander/bithacks.html  #####" << endl;
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    cout << "when signed integers are shifted right, the value of the far " << endl;
    cout << "left bit is copied. to the other bits; all 1 bits gives -1." << endl;
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    cout << "-100: " << (-100 >> 31) << endl;
    cout << "+100: " << (100 >> 31) << endl;
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    cout << "Detect if two integers have opposite signs" << endl;
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    cout << "-1 and +1: " << ((-1 ^ 1) < 0) << endl;
    cout << "+1 and +2: " << ((1 ^ 2) < 0) << endl;
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    cout << "Compute the integer absolute value (abs) without branching" << endl;
    cout << "(v ^ mask) - mask where v is the value and mask is the sign" << endl;
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    cout << (-1000 ^ -1) - (-1) << endl;
    cout << (1000 ^ 0) - 0 << endl;
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    cout << "Comopute the minimum or maximum of two integers without branching" << endl;
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    int x = 10;
    int y = 9;
    cout << (y ^ ((x ^ y) & -(x < y))) << endl; // min(x, y)
    cout << (x ^ ((x ^ y) & -(x < y))) << endl; // max(x, y)
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    cout << "Determining if an integer is a power of 2" << endl;
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    cout << "8: " << ((8 & 8 - 1) == 0) << endl;
    cout << "9: " << ((9 & 9 - 1) == 0) << endl;
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    cout << "Swapping values with XOR" << endl;
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    x ^= y;
    y ^= x;
    x ^= y;
    cout << "[BEFORE] x = 10, y = 9: \n[AFTER] x:" << x << " y: " << y << endl;
    cout << "##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####" << endl;
    return 0;
}
