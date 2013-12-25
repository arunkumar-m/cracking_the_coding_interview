# Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

## Time Complexity

I simply compare the head of k lists and select the largest element among them and add it to the new list. The time complexity would be O(nk).

Can use a heap to reduce the number of comparisons achieving a time
complexity of O(nlog k). I didn't give it a
try because the dumb way can pass the large test already.
