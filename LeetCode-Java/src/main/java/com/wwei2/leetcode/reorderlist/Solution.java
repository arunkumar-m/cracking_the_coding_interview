package com.wwei2.leetcode.reorderlist;

import com.wwei2.leetcode.util.ListNode;

/**
 * Reorder list.
 *
 * For example, given {1, 2, 3, 4} return {1, 4, 2, 3}
 */
public class Solution {
  public void reorderList(ListNode head) {
    if (head == null) {
      return;
    }
    ListNode slow = head;
    ListNode fast = head;
    while (slow.next != null && fast.next != null && fast.next.next != null) {
      slow = slow.next;
      fast = fast.next.next;
    }
    ListNode head2 = slow.next;
    slow.next = null;
    merge(head, reverse(head2));
  }
  private ListNode reverse(ListNode head) {
    ListNode dummy = new ListNode(0);
    ListNode curr = head;
    while (curr != null) {
      ListNode next = curr.next;
      curr.next = dummy.next;
      dummy.next = curr;
      curr = next;
    }
    return dummy.next;
  }
  private void merge(ListNode head, ListNode other) {
    while (other != null) {
      ListNode next1 = head.next;
      ListNode next2 = other.next;
      head.next = other;
      other.next = next1;
      head = next1;
      other = next2;
    }
  }
}
