package com.wwei2.leetcode.removeduplicatesfromsortedlist;

import com.wwei2.leetcode.util.ListNode;

/**
 * Remove duplicates from sorted list.
 */
public class Solution {
  public ListNode deleteDuplicates(ListNode head) {
    return deleteDuplicatesIterative(head);
  }

  // Recursive solution.
  private ListNode deleteDuplicatesRecursive(ListNode head) {
    if (head == null) {
      return null;
    }
    ListNode tail = deleteDuplicates(head.next);
    if (tail == null) {
      head.next = null;
      return head;
    } else if (head.val == tail.val) {
      return tail;
    } else {
      head.next = tail;
      return head;
    }
  }

  // Iterative solution.
  private ListNode deleteDuplicatesIterative(ListNode head) {
    if (head == null) {
      return null;
    }
    ListNode prev = head;
    ListNode curr = head.next;
    while (curr != null) {
      if (prev.val == curr.val) {
        prev.next = curr.next;
      } else {
        prev.next = curr;
        prev = curr;
      }
      curr = curr.next;
    }
    return head;
  }
}
