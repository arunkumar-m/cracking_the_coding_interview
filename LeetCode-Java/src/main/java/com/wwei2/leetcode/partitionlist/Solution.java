package com.wwei2.leetcode.partitionlist;

import com.wwei2.leetcode.util.ListNode;

/**
 * Partition list.
 */
public class Solution {
  public ListNode partition(ListNode head, int x) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode prev = dummy; // Maintain the parent of the current node.
    ListNode curr = head; // Current node.
    ListNode pivot = dummy; // Always at the last element that is smaller.
    while (curr != null) {
      ListNode next = curr.next;
      if (curr.val < x) {
        if (curr != pivot.next) {
          prev.next = next;
          curr.next = pivot.next;
          pivot.next = curr;
        }
        pivot = curr;
      } else {
        prev = curr;
      }
      curr = next;
    }
    return dummy.next;
  }
}
