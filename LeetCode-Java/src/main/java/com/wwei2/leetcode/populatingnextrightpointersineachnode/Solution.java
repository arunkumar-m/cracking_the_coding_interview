package com.wwei2.leetcode.populatingnextrightpointersineachnode;

import com.wwei2.leetcode.util.TreeLinkNode;

/**
 * Populating Next Right Pointers in Each Node.
 */
public class Solution {
  public void connect(TreeLinkNode root) {
    if (root == null) {
      return;
    }
    if (root.left != null) {
      root.left.next = root.right;
    }
    if (root.next != null && root.right != null) {
      root.right.next = root.next.left;
    }
    connect(root.left);
    connect(root.right);
  }
}
