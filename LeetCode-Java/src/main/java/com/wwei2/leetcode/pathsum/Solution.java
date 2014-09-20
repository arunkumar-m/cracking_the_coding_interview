package com.wwei2.leetcode.pathsum;

import com.wwei2.leetcode.util.TreeNode;

/**
 * Path sum.
 */
public class Solution {
  public boolean hasPathSum(TreeNode root, int sum) {
    if (root == null) {
      return false;
    }
    if (root.left == null && root.right == null && sum == root.val) {
      return true;
    }
    return hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val);
  }
}
