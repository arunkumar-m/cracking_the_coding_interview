package com.wwei2.leetcode.mergetwosortedlists;

import com.wwei2.leetcode.util.ListNode;

/**
 * Merge Two Sorted Lists.
 */
public class Solution {
  public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    return mergeTwoListsRecursive(l1, l2);
  }

  // Recursive solution.
  private ListNode mergeTwoListsRecursive(ListNode l1, ListNode l2) {
    if (l1 == null) {
      return l2;
    }
    if (l2 == null) {
      return l1;
    }
    if (l1.val <= l2.val) {
      ListNode tmp = mergeTwoLists(l1.next, l2);
      l1.next = tmp;
      return l1;
    } else {
      ListNode tmp = mergeTwoLists(l1, l2.next);
      l2.next = tmp;
      return l2;
    }
  }

  // Iterative solution.
  private ListNode mergeTwoListsIterative(ListNode l1, ListNode l2) {
    ListNode dummy = new ListNode(0);
    ListNode curr = dummy;
    while (l1 != null && l2 != null) {
      if (l1.val <= l2.val) {
        curr.next = l1;
        l1 = l1.next;
      } else {
        curr.next = l2;
        l2 = l2.next;
      }
      curr = curr.next;
    }
    while (l1 != null) {
      curr.next = l1;
      curr = curr.next;
      l1 = l1.next;
    }
    while (l2 != null) {
      curr.next = l2;
      curr = curr.next;
      l2 = l2.next;
    }
    return dummy.next;
  }
}
