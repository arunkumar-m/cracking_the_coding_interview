# Sort List

Sort a linked list in O(n log n) time using constant space complexity.

    /**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
    */

## Merge sort

merge_sort_list.cpp is an iterative implementation of merge sort. It
uses extra space but is very time efficient.

## Quick sort

quick_sort_list.cpp is an implementation of quick sort for linked list.
However, it failed the large test case of LeetCode. The reason it is
very slow may be the fact that _partition_ doesn't choose the pivot
randomly.
