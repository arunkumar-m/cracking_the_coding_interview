/*
 * =====================================================================================
 *
 *       Filename:  max_area.cpp
 *
 *        Version:  1.0
 *        Created:  12/01/2013 11:48:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

/*// O(n^2), time limit exceeded
int maxArea(vector<int> &height) {
    int len = height.size();
    int max_so_far = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            max_so_far = max(max_so_far, min(height[i], height[j]) * (j - i));
        }
    }
    return max_so_far;
}*/

// Time complexity: O(n)
int maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int max_so_far = 0;
    while (left < right) {
        int tmp = min(height[left], height[right]) * (right - left);
        if (tmp > max_so_far) {
            max_so_far = tmp;
        }
        if (height[left] > height[right]) {
            right--;
        }
        else {
            left++;
        }
    }
    return max_so_far;
}

int main() {
    int h[] = {3,4,4,2};
    int length = sizeof(h) / sizeof(h[0]);
    cout << "LENGTH: " << length << endl;
    vector<int> height(sizeof(h) / sizeof(h[0]));
    height.assign(h, h + length);
    cout << maxArea(height) << endl;
    return 0;
}
