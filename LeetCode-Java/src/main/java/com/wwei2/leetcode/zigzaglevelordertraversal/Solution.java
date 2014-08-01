package com.wwei2.leetcode.zigzaglevelordertraversal;

import com.wwei2.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * Binary tree zigzag level order traversal.
 */
public class Solution {
  public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    Stack<TreeNode> currentLevel = new Stack<>();
    Stack<TreeNode> nextLevel = new Stack<>();
    List<List<Integer>> ret = new ArrayList<>();
    boolean leftToRight = false;
    if (root != null) {
      currentLevel.add(root);
    }
    List<Integer> tmp = new ArrayList<>();
    while (!currentLevel.isEmpty()) {
      TreeNode node = currentLevel.pop();
      if (node != null) {
        tmp.add(node.val);
        if (leftToRight) {
          nextLevel.push(node.right);
          nextLevel.push(node.left);
        } else {
          nextLevel.push(node.left);
          nextLevel.push(node.right);
        }
      }
      if (currentLevel.isEmpty()) {
        leftToRight = !leftToRight;
        currentLevel = nextLevel;
        if (!tmp.isEmpty()) {
          ret.add(tmp);
        }
        nextLevel = new Stack<>();
        tmp = new ArrayList<>();
      }
    }
    return ret;
  }
}
