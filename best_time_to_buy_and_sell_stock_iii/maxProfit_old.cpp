/*
 * =====================================================================================
 *
 *       Filename:  maxProfit.cpp
 *
 *        Version:  1.0
 *        Created:  11/25/2013 23:39:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

int maxProfitHelper(vector<int> &prices) {
    if (prices.size() == 0)
        return 0;
    int max_so_far = 0;
    int lowest = prices[0];
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < lowest) {
            lowest = prices[i];
        }
        max_so_far =  max(max_so_far, prices[i] - lowest);
    }
    return max_so_far;
}

int maxProfit(vector<int> &prices) {
    int length = prices.size();
    int max_so_far = 0;
    for (int i = 0; i < length; i++) {
        vector<int> v1(prices.begin(), prices.begin() + i);
        vector<int> v2(prices.begin() + i, prices.end());
        int p1 = maxProfitHelper(v1);
        int p2 = maxProfitHelper(v2);
        max_so_far = max(max_so_far, p1 + p2);
    }
    return max_so_far;
}

int main() {
    int p[] = {};
    vector<int> prices (p, p + sizeof(p) / sizeof(int));
    cout << maxProfit(prices) << endl;
    return 0;
}
