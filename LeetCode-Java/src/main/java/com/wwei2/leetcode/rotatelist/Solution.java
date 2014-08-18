package com.wwei2.leetcode.rotatelist;

import com.wwei2.leetcode.util.ListNode;

/**
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 */
public class Solution {
  public ListNode rotateRight(ListNode head, int n) {
    // Get the length of the list.
    if (head == null || n == 0) {
      return head;
    }
    int length = 1;
    ListNode curr = head;
    while (curr.next != null) {
      length++;
      curr = curr.next;
    }
    // Form a loop.
    curr.next = head;
    // Break the loop.
    int k = length - n % length;
    for (int i = 0; i < k; i++) {
      curr = curr.next;
    }
    ListNode newHead = curr.next;
    curr.next = null;
    return newHead;
  }
}
