package com.wwei2.leetcode.uniquebst2;

import com.wwei2.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Unique binary search tree.
 */
public class Solution {
  public List<TreeNode> generateTrees(int n) {
    List<Integer> integers =new ArrayList<>();
    for (int i = 1; i <= n; i++) {
      integers.add(i);
    }
    return generateTreeHelper(1, n);
  }
  private List<TreeNode> generateTreeHelper(int start, int end) {
    List<TreeNode> results = new ArrayList<>();
    if (end < start) {
      results.add(null);
      return results;
    }
    for (int i = start; i <= end; i++) {
      List<TreeNode> lefts = generateTreeHelper(start, i - 1);
      List<TreeNode> rights = generateTreeHelper(i + 1, end);
      for (TreeNode left : lefts) {
        for (TreeNode right : rights) {
          TreeNode root = new TreeNode(i);
          root.left = left;
          root.right = right;
          results.add(root);
        }
      }
    }
    return results;
  }
}
