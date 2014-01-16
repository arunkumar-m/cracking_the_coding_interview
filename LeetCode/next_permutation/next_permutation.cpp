/*
 * =====================================================================================
 *
 *       Filename:  next_permutation.cpp
 *
 *        Version:  1.0
 *        Created:  12/19/2013 21:40:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void reverse(vector<int> &num, int begin, int end) {
    while (begin < end) {
        swap(num[begin], num[end]);
        begin++;
        end--;
    }
}

void nextPermutation(vector<int> &num) {
    int length = num.size();
    int pos = length - 1;
    for (int i = length - 1; i > 0; i--) {
        if (num[i] <= num[i - 1]) {
            pos = i - 1;
        }
        else {
            break;
        }
    }

    if (pos == 0) {
        reverse(num, 0, length - 1);
        return;
    }

    int minimum = 0x7FFFFFFF;
    int ind = -1;
    for (int i = pos; i < length; i++) {
        if (num[i] > num[pos - 1]) {
            minimum = min(num[i], minimum);
            ind = i;
        }
    }
    swap(num[ind], num[pos - 1]);
    reverse(num, pos, length - 1);
}

void printVector(vector<int> &num) {
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1,1,1,4};
    vector<int> num(4);
    num.assign(arr, arr + 4);
    for (int i = 0; i < 25; i++) {
        printVector(num);
        nextPermutation(num);
    }
    return 0;
}
