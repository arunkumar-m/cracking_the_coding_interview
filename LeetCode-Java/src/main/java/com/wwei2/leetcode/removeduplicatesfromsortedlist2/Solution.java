package com.wwei2.leetcode.removeduplicatesfromsortedlist2;

import com.wwei2.leetcode.util.ListNode;

/**
 * Given a sorted linked list, delete all nodes that have duplicates numbers,
 * leaving only distinct numbers from the original list.
 */
public class Solution {
  public ListNode deleteDuplicates(ListNode head) {
    return deleteDuplicatesTwoPointers(head);
  }

  // Using two pointers to test if the element is distinct.
  private ListNode deleteDuplicatesTwoPointers(ListNode head) {
    if (head == null) {
      return null;
    }
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode prev = dummy;
    ListNode curr = head;
    while (curr != null) {
      ListNode next = curr.next;
      while (next != null && curr.val == next.val) {
        curr = next;
        next = next.next;
      }
      if (prev.next == curr) {
        prev = curr;
      } else {
        prev.next = next;
        curr = next;
      }
    }
    return dummy.next;
  }

  // Using three pointers to test if the element is distinct.
  private ListNode deleteDuplicatesThreePointers(ListNode head) {
    if (head == null) {
      return null;
    }
    ListNode result = new ListNode(0); // Dummy head.
    ListNode ptr = result;
    ListNode dummy = new ListNode(head.val - 1);
    dummy.next = head;
    ListNode prev = dummy;
    ListNode curr = head;
    ListNode next = head.next;
    while (next != null) {
      if (prev.val != curr.val && curr.val != next.val) {
        ptr.next = curr;
        curr.next = null;
        ptr = ptr.next;
      }
      prev = curr;
      curr = next;
      next = next.next;
    }
    if (prev.val != curr.val) {
      ptr.next = curr;
      curr.next = null;
    }
    return result.next;
  }
}
