package com.wwei2.leetcode.validbst;

import com.wwei2.leetcode.util.TreeNode;

/**
 * Given a binary search tree, determine if it is a valid binary search tree.
 */
public class Solution {
  public boolean isValidBST(TreeNode root) {
    return isValidBSTHelper(root, new TreeNode(Integer.MIN_VALUE));
  }

  private boolean isValidBSTHelper(TreeNode root, TreeNode prev) {
    if (root == null) {
      return true;
    }
    if (isValidBSTHelper(root.left, prev)) {
      if (prev.val >=  root.val) {
        return false;
      }
      prev.val = root.val;
      return isValidBSTHelper(root.right, prev);
    }
    return false;
  }
}
