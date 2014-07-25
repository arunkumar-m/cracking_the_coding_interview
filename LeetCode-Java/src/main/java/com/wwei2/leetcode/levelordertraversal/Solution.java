package com.wwei2.leetcode.levelordertraversal;

import com.wwei2.leetcode.util.TreeNode;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * Binary tree level order traversal.
 */
public class Solution {
  public List<List<Integer>> levelOrder(TreeNode root) {
    List<List<Integer>> results = new LinkedList<List<Integer>>();
    Queue<TreeNode> queue = new LinkedList<TreeNode>();
    if (root != null) {
      queue.add(root);
      queue.add(null);
    }
    List<Integer> tmp = new LinkedList<Integer>();
    while (!queue.isEmpty()) {
      TreeNode node = queue.remove();
      if (node == null) {
        if (!queue.isEmpty()) {
          queue.add(null);
        }
        results.add(tmp);
        tmp = new LinkedList<Integer>();
      } else {
        if (node.left != null) {
          queue.add(node.left);
        }
        if (node.right != null) {
          queue.add(node.right);
        }
        tmp.add(node.val);
      }
    }
    return results;
  }
}
