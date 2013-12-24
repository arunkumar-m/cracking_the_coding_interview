/*
 * =====================================================================================
 *
 *       Filename:  get_permutation.cpp
 *
 *        Version:  1.0
 *        Created:  12/23/2013 16:49:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

void getNext(string &str) {
    int i, j;
    int index1 = -1;
    for (i = 0; i < str.length() - 1; i++) {
        if (str[i] < str[i + 1]) {
            index1 = i;
        }
    }
    if (index1 == -1) {
        reverse(str.begin(), str.end());
        return;
    }
    int index2 = index1 + 1;
    for (j = index1 + 1; j < str.length(); j++) {
        if (str[j] >= str[index1]) {
            index2 = j;
        }
    }
    swap(str[index1], str[index2]);
    reverse(str.begin() + index1 + 1, str.end());
}

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

string getPermutation(int n, int k) {
    int visited[10] = {0};
    int data[10];
    k--;
    for (int i = n; i > 0; i--) {
        int num = k / factorial(i - 1) + 1;
        k = k % factorial(i - 1);
        // cout << fact << " " << num << " " << k << endl;
        int cnt = 0, index;
        for (int j = 1; j <= n; j++) {
            if (visited[j] != 1) {
                cnt++;
                if (cnt == num) {
                    num = j;
                    break;
                }
            }
        }
        data[i] = num;
        visited[num] = 1;
    }
    string result;
    for (int i = n; i > 0; i--) {
        result += data[i] + '0';
    }
    return result;
}

int main() {
    for (int i = 1; i <= 10; i++) {
        cout << getPermutation(3, i) << endl;
    }
    return 0;
}
