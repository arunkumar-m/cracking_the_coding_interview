# Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


## Solution

Assume there are n_k distinct ways to climb to the top where k is the
number of steps to reach to the top.

Then we have n_k = n\_(k-1) + n\_(k-2)
