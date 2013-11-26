# Best Time to Buy and Sell Stock III

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

__Note:__
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

## Solution 1

A simple solution is that we can split the vector of _prices_ into two
pieces and use the function we write in the first problem of this series *best_time_to_buy_and_sell_stock* to calculate the maximum profit we can get using these two pieces.

However, this algorithm's time complexity is _O(n^2)_, which would take
a lot of time and didn't pass the large test case on LeetCode OJ.

## Solution 2

Solution 2 is not that straight forward compared to solution 1.

This solution iterator from index _0_ to index _prices.size() - 1_ and
we use a new vector _profit_ to record the highest value we can get using elements from index _0_ to
index _i_ and store it in _profit[i]_.

Then we iterate from index _prices.size() - 1_ back to 0 to and try to
calculate the maximum we can get by combining the left part and the
right part.

This algorithm requires _O(n)_ time.
