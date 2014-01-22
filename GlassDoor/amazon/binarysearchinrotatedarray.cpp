/*
 * =====================================================================================
 *
 *       Filename:  binarysearchinrotatedarray.cpp
 *
 *        Version:  1.0
 *        Created:  01/22/2014 10:58:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int binarysearch(int A[], int n, int key) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
//        cout << "index: " << left << " " << mid << " " << right << endl;
//        cout << "value: " << A[left] << " " << A[mid] << " " << A[right] << endl;
        if (A[mid] == key) {
//            cout << "==" << endl;
            return mid;
        }
        else if (A[mid] < key) {
//            cout << "<" << endl;
            if (A[mid] < A[right] && key <= A[right]) {
                left = mid + 1;
            }
            else {
//                cout << "right--" << endl;
                right--;
            }
        }
        else if (A[mid] > key) {
//            cout << ">" << endl;
            if (A[mid] > A[left] && key >= A[left]) {
                right = mid - 1;
            }
            else {
//                cout << "left++" << endl;
                left++;
            }
        }
    }
    return -1;
}

int main() {
    int arr[] = {6,7,8,9,10,1,2,3,4,5};
    cout << binarysearch(arr, 10, 1) << endl;
    cout << binarysearch(arr, 10, 2) << endl;
    cout << binarysearch(arr, 10, 3) << endl;
    cout << binarysearch(arr, 10, 4) << endl;
    cout << binarysearch(arr, 10, 5) << endl;
    cout << binarysearch(arr, 10, 6) << endl;
    cout << binarysearch(arr, 10, 7) << endl;
    cout << binarysearch(arr, 10, 8) << endl;
    cout << binarysearch(arr, 10, 9) << endl;
    cout << binarysearch(arr, 10, 10) << endl;
    cout << binarysearch(arr, 10, 11) << endl;
    return 0;
}
