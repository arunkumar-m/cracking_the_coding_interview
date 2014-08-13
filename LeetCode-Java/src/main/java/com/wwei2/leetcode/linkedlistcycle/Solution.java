package com.wwei2.leetcode.linkedlistcycle;

import com.wwei2.leetcode.util.ListNode;

/**
 * Linked List Cycle.
 */
public class Solution {
  public boolean hasCycle(ListNode head) {
    if (head == null) {
      return false;
    }
    ListNode slow = head;
    ListNode fast = head;
    while (slow.next != null && fast.next != null && fast.next.next != null) {
      slow = slow.next;
      fast = fast.next.next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
}
