package com.wwei2.leetcode.inordertraversal;

import com.wwei2.leetcode.util.TreeNode;

import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

/**
 * Created by weiwei on 8/4/14.
 */
public class Solution {
  public List<Integer> inorderTraversal(TreeNode root) {
    List<Integer> results = new LinkedList<>();
    Stack<TreeNode> stack = new Stack<>();
    TreeNode current = root;
    boolean done = false;
    while (!done) {
      if (current != null) {
        stack.push(current);
        current = current.left;
      } else {
        if (stack.isEmpty()) {
          done = true;
        } else {
          TreeNode node = stack.pop();
          results.add(node.val);
          current = node.right;
        }
      }
    }
    return results;
  }
}
