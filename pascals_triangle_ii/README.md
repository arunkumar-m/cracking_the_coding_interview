# Pascal's Triangle II

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,

    Return [1,3,3,1].

**Note:**

Could you optimize your algorithm to use only O(k) extra space?

## Solution

Pascal's triangle determines the coefficients which arise in binomial expansions. Maybe we can use this property to calculate a specific row of pascal's triangle.

(if you calculate n choose r using factorial(n) / factorial(r) / factorial(n - r), then you may get errors because this number may so large that it exceeds the range of integer.)
