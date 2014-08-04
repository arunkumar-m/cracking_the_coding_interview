package com.wwei2.leetcode.recoverbst;

import com.wwei2.leetcode.util.TreeNode;

import java.util.Stack;

/**
 * Recover binary search tree.
 */
public class Solution {
  public void recoverTree(TreeNode root) {
    Stack<TreeNode> stack = new Stack<>();
    TreeNode node1 = null, node2 = null;
    TreeNode current = root, prev = new TreeNode(Integer.MIN_VALUE);
    boolean flag = true, done = false;
    while (!done) {
      if (current != null) {
        stack.push(current);
        current = current.left;
      } else {
        if (stack.isEmpty()) {
          done = true;
        } else {
          current = stack.pop();
          if (prev.val > current.val) {
            if (flag) {
              node1 = prev;
              node2 = current;
              flag = false;
            } else {
              node2 = current;
            }
          }
          prev = current;
          current = current.right;
        }
      }
    }
    int tmp = node1.val;
    node1.val = node2.val;
    node2.val = tmp;
  }
}