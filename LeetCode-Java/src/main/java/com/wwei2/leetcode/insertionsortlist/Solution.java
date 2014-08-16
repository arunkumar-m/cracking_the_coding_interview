package com.wwei2.leetcode.insertionsortlist;

import com.wwei2.leetcode.util.ListNode;

/**
 * Sort a linked list using insertion sort.
 */
public class Solution {
  public ListNode insertionSortList(ListNode head) {
    if (head == null) {
      return head;
    }
    ListNode result = insertionSortList(head.next);
    ListNode dummy = new ListNode(0);
    dummy.next = result;
    ListNode prev = dummy;
    ListNode curr = result;
    while (curr != null) {
      if (curr.val > head.val) {
        ListNode next = prev.next;
        prev.next = head;
        head.next = next;
        return dummy.next;
      }
      prev = curr;
      curr = curr.next;
    }
    prev.next = head;
    head.next = null;
    return dummy.next;
  }
}
