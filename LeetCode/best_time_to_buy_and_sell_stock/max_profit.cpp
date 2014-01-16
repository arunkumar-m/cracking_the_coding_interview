/*
 * =====================================================================================
 *
 *       Filename:  max_profit.cpp
 *
 *        Version:  1.0
 *        Created:  11/25/2013 23:12:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
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

int main() {
    vector<int> prices;
    prices.push_back(10);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(9);
    prices.push_back(11);
    prices.push_back(11);
    cout << maxProfit(prices) << endl;
    return 0;
}
