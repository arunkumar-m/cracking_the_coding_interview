package com.wwei2.leetcode.sametree;

import com.wwei2.leetcode.util.TreeNode;

/**
 * Is same tree?
 */
public class Solution {
  public boolean isSameTree(TreeNode p, TreeNode q) {
    if (p != null && q != null) {
      return p.val == q.val && isSameTree(p.left, q.left) &&
          isSameTree(p.right, q.right);
    } else if (p == null && q == null) {
      return true;
    } else {
      return false;
    }
  }
}