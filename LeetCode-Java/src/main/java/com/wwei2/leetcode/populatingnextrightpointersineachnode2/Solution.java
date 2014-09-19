package com.wwei2.leetcode.populatingnextrightpointersineachnode2;

import com.wwei2.leetcode.util.TreeLinkNode;

/**
 * Populating next right pointers in each node II.
 */
public class Solution {
  public void connect(TreeLinkNode root) {
    if (root == null) {
      return;
    }
    TreeLinkNode next = root.next;
    while (next != null) {
      if (next.left != null) {
        next = next.left;
        break;
      } else if (next.right != null) {
        next = next.right;
        break;
      }
      next = next.next;
    }
    if (root.right != null) {
      root.right.next = next;
    }
    connect(root.right);
    if (root.left != null) {
      if (root.right != null) {
        root.left.next = root.right;
      } else {
        root.left.next = next;
      }
    }
    connect(root.left);
  }
}
