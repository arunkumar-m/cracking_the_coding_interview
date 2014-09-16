package com.wwei2.leetcode.sumroottoleafnumbers;

import com.wwei2.leetcode.util.Pair;
import com.wwei2.leetcode.util.TreeNode;

import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

/**
 * Sum root to leaf numbers.
 */
public class Solution {
  public int sumNumbers(TreeNode root) {
    int sum = 0;
    Stack<Pair<TreeNode, String>> stack = new Stack<>();
    stack.push(new Pair<TreeNode, String>(root, ""));
    while (!stack.isEmpty()) {
      Pair<TreeNode, String> pair = stack.pop();
      TreeNode node = pair.getFirst();
      String digits = pair.getSecond();
      if (node != null) {
        if (node.left == null && node.right == null) {
          sum += Integer.parseInt(digits + node.val);
        }
        stack.push(new Pair<TreeNode, String>(node.left, digits + node.val));
        stack.push(new Pair<TreeNode, String>(node.right, digits + node.val));
      }
    }
    return sum;
  }
}
