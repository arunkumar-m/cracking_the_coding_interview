/*
 * =====================================================================================
 *
 *       Filename:  missingint.cpp
 *
 *        Version:  1.0
 *        Created:  01/24/2014 13:07:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int binsearch(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        // cout << left << " " << mid << " " << right << endl;
        // cout << arr[left] << " " << arr[mid] << " " << arr[right] << endl;
        if (arr[mid] - arr[left] != mid - left) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    return arr[right] - arr[left] == 1 ? -1 : arr[left] + 1;
}

int main() {
    int arr[] = {1,3};
    cout << binsearch(arr, 2) << endl;
    return 0;
}
