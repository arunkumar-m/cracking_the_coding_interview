package com.wwei2.leetcode.symmetrictree;

import com.wwei2.leetcode.util.TreeNode;

import java.util.*;

/**
 * Is the tree a mirror of itself?
 */
public class Solution {

  private boolean traversal(TreeNode left, TreeNode right) {
    if (left == null && right == null) {
      return true;
    } else if (left != null && right != null && left.val == right.val) {
      return traversal(left.left, right.right) && traversal(left.right, right.left);
    } else {
      return false;
    }
  }

  public boolean isSymmetric(TreeNode root) {
    return root == null ? true : traversal(root.left, root.right);
  }
}
