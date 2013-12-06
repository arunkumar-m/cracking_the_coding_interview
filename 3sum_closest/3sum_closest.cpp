/*
 * =====================================================================================
 *
 *       Filename:  3sum_closest.cpp
 *
 *        Version:  1.0
 *        Created:  12/05/2013 21:48:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

void printV(vector<int> result);

vector<int> merge(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int j = 0, k = 0;
    for (int i = 0; i < A.size() + B.size(); i++) {
        if (j < A.size() && k < B.size() && A[j] < B[k]) {
            C.push_back(A[j]);
            j++;
        }
        else if (j < A.size() && k < B.size() && A[j] >= B[k]) {
            C.push_back(B[k]);
            k++;
        }
        else if (j == A.size()) {
            C.push_back(B[k]);
            k++;
        }
        else {
            C.push_back(A[j]);
            j++;
        }
    }
    return C;
}

vector<int> merge_sort(vector<int> &num, int left, int right) {
    vector<int> result;
    if (left > right) {
        return result;
    }
    if (left == right) {
        result.push_back(num[left]);
        return result;
    }
    vector<int> A = merge_sort(num, left, (right + left) / 2);
    vector<int> B = merge_sort(num, (right + left) / 2 + 1, right);
    vector<int> C = merge(A, B);
    return C;
}

int threeSumClosest(vector<int> &num, int target) {
    int len = num.size();
    vector<int> sorted = merge_sort(num, 0, len - 1);
    int i = 0, j = 0, k = len - 1, sum, closest_so_far = sorted[0] + sorted[1] + sorted[2], gap = abs(closest_so_far - target);
    for (i = 0; i < len; i++) {
        j = i + 1;
        k = len - 1;
        while (j < k) {
            sum = sorted[i] + sorted[j] + sorted[k];
            if (abs(sum - target) <= gap) {
                gap = abs(sum - target);
                closest_so_far = sum;
            }
            if (sum == target) {
                return sum;
            }
            else if (sum - target> 0) {
                k--;
            }
            else if (sum - target < 0) {
                j++;
            }
        }
    }
    return closest_so_far;
}

void printV(vector<int> result) {
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {0,5,-1,-2,4,-1,0,-3,4,-5};
    vector<int> num(10);
    num.assign(arr, arr + 10);
    cout << threeSumClosest(num, 1) << endl;
    return 0;
}
