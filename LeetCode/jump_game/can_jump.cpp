/*
 * =====================================================================================
 *
 *       Filename:  can_jump.cpp
 *
 *        Version:  1.0
 *        Created:  12/05/2013 22:31:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

/* Worst case O(n^2) */
bool canJump(int A[], int n) {
    int can_reach = 0;
    for (int i = 0; i < n && i <= can_reach; i++) {
        can_reach = max(can_reach, i + A[i]);
    }
    return can_reach >= n - 1;
}

int main() {
    int A[] = {2,3,1,1,4};
    cout << canJump(A, 5) << endl;
    int B[] = {3,2,1,0,4};
    cout << canJump(B, 5) << endl;
    int C[] = {1,3,4,1,1,3,3};
    cout << canJump(C, 7) << endl;
    return 0;
}
