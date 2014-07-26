package com.wwei2.leetcode.levelordertraversal2;

import com.wwei2.leetcode.util.TreeNode;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * Level order traversal from left to right, from leaf to root.
 */
public class Solution {
  public List<List<Integer>> levelOrderBottom(TreeNode root) {
    List<List<Integer>> results = new LinkedList<List<Integer>>();
    Queue<TreeNode> currentLevel = new LinkedList<TreeNode>();
    Queue<TreeNode> nextLevel = new LinkedList<TreeNode>();
    if (root == null) {
      return results;
    } else {
      currentLevel.add(root);
    }
    List<Integer> tmp = new LinkedList<Integer>();
    while (!currentLevel.isEmpty()) {
      TreeNode node = currentLevel.remove();
      if (node != null) {
        tmp.add(node.val);
        nextLevel.add(node.left);
        nextLevel.add(node.right);
      }
      if (currentLevel.isEmpty()) {
        if (!tmp.isEmpty()) {
          results.add(0, tmp);
        }
        tmp = new LinkedList<Integer>();
        currentLevel = nextLevel;
        nextLevel = new LinkedList<TreeNode>();
      }
    }
    return results;
  }
}
