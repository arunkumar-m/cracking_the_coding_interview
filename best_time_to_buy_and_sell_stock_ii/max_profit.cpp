/*
 * =====================================================================================
 *
 *       Filename:  max_profit.cpp
 *
 *        Version:  1.0
 *        Created:  11/25/2013 23:21:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
    if (prices.size() < 2)
        return 0;
    vector<int> diff;
    for (int i = 0; i < prices.size() - 1; i++) {
        diff.push_back(prices[i + 1] - prices[i]);
    }
    int sum = 0;
    for (int i = 0; i < diff.size(); i++) {
        if (diff[i] > 0) {
            sum += diff[i];
        }
    }
    return sum;
}

int main() {
    // int p[] = {5,1,2,7,6,2,1,10};
    int p[] = {1,3,2,1};
    vector<int> prices (p, p + sizeof(p) / sizeof(int));
    cout << maxProfit(prices) << endl;
    return 0;
}
