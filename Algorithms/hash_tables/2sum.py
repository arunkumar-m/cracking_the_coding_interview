# Problem Statement
# The goal of this problem is to implement a variant of the 2-SUM algorithm (covered in the Week 6 lecture on hash table applications).
# The file contains 1 million integers, both positive and negative (there might be some repetitions!).This is your array of integers, with the ith row of the file specifying the ith entry of the array.
# Your task is to compute the number of target values t in the interval [-10000,10000] (inclusive) such that there are distinct numbers x,y in the input file that satisfy x+y=t. (NOTE: ensuring distinctness requires a one-line addition to the algorithm from lecture.)
# Write your numeric answer (an integer between 0 and 20001) in the space provided.
# OPTIONAL CHALLENGE: If this problem is too easy for you, try implementing your own hash table for it. For example, you could compare performance under the chaining and open addressing approaches to resolving collisions.

## First sort the data, then use bisect to search (binary search under the hood?)
# The time complexity of this algorithm is O(n log n)

from bisect import *

print 'Loading data ...'
data = open('algo1-programming_prob-2sum.txt', 'r').readlines()
print 'Data loaded!'

data = map(int, data)
data = list(set(data))
data.sort()
print 'Data sorted'

ans = set([])
for x in data:
    posl = bisect_left(data, -10000-x)
    posr = bisect_right(data, 10000-x)
    for y in data[posl:posr]:
        if x != y:
            ans.add(x + y)

print "Answer:", len(ans)

# If hash table is correctly implemented, two sum problem can be solved in O(n), in this problem, it can be solved within O(20000n) which is still O(n)
# However, python's lookup operation's time complexity is not O(1), maybe O(log n) or even worse, so it is really slow
# Really slow!

table = set(data)
ans = set([])
j = 0
for x in data:
    print j
    j += 1
    for i in range(-10000,10000):
        if i - x in table:
            ans.add(i)

print "Answer:", len(ans)
