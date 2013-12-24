/*
 * =====================================================================================
 *
 *       Filename:  largest_rectangle_area.cpp
 *
 *        Version:  1.0
 *        Created:  12/23/2013 20:48:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int> &height) {
    stack<int> S;
    height.push_back(0);
    int sum = 0;
    for (int i = 0; i < height.size(); i++) {
        if (S.empty() || height[i] > height[S.top()]) {
            S.push(i);
        }
        else {
            int tmp = S.top();
            S.pop();
            sum = max(sum, height[tmp] * (S.empty() ? i : i - S.top() - 1));
            i--;
        }
    }
    return sum;
}

int main() {
    vector<int> height;
    int arr[] = {5,6,7,6,5,3,2};
    height.assign(arr, arr + 6);
    cout << largestRectangleArea(height) << endl;
    return 0;
}
