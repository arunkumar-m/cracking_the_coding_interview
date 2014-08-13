package com.wwei2.leetcode.linkedlistcycle2;

import com.wwei2.leetcode.util.ListNode;

/**
 * Linked List Cycle II.
 *
 * Given a linked list, return the node where the cycle begins.
 * If there is no cycle, return null.
 *
 */
public class Solution {
  public ListNode detectCycle(ListNode head) {
    // First judge if there is a cycle.
    if (head == null) {
      return null;
    }
    ListNode slow = head, fast = head;
    while (true) {
      if (slow != null && fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
      } else {
        return null;
      }
      if (fast == slow) {
        break;
      }
    }
    // Find the node where the cycle begins.
    slow = head;
    while (slow != fast) {
      slow = slow.next;
      fast = fast.next;
    }
    return slow;
  }
}
