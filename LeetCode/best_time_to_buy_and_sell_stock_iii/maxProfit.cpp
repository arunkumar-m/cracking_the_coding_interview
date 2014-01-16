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

int maxProfit(vector<int> &prices) {
    int length = prices.size();
    if (length <= 1)
        return 0;
    vector<int> profit;
    profit.push_back(0);
    int lowest = prices[0];
    for (int i = 1; i < length; i++) {
        if (lowest > prices[i]) {
            lowest = prices[i];
        }
        profit.push_back(max(profit[i - 1], prices[i] - lowest));
    }

    int max_so_far = profit[length - 1];
    int greatest = prices[length - 1];
    for (int i = length - 1; i > 0; i--) {
        if (greatest < prices[i]) {
            greatest = prices[i];
        }
        // cout << "i: " << i << "\t" << profit[i - 1] << " " << greatest - prices[i] << endl;
        max_so_far = max(max_so_far, profit[i - 1] + greatest - prices[i]);
    }
    return max_so_far;
}

int main() {
    int p[] = {1,2};
    vector<int> prices (p, p + sizeof(p) / sizeof(int));
    cout << maxProfit(prices) << endl;
    return 0;
}
