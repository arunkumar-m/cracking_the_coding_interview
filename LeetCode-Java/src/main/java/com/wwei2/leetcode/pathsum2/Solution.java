package com.wwei2.leetcode.pathsum2;

import com.wwei2.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Path sum 2.
 */
public class Solution {
  public List<List<Integer>> pathSum(TreeNode root, int sum) {
    List<Integer> curr = new ArrayList<>();
    List<List<Integer>> result = new ArrayList<>();
    pathSumHelper(root, sum, curr, result);
    return result;
  }
  public void pathSumHelper(TreeNode root, int sum, List<Integer> curr, List<List<Integer>> result) {
    if (root == null) {
      return;
    }
    if (root.left == null && root.right == null && root.val == sum) {
      List<Integer> tmp = new ArrayList<Integer>(curr);
      tmp.add(root.val);
      result.add(tmp);
    }
    curr.add(root.val);
    pathSumHelper(root.left, sum - root.val, curr, result);
    pathSumHelper(root.right, sum - root.val, curr, result);
    curr.remove(curr.size() - 1);
  }
}
