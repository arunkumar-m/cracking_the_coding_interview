package com.wwei2.leetcode.postordertraversal;

import com.wwei2.leetcode.util.Pair;
import com.wwei2.leetcode.util.TreeNode;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

/**
 * Created by weiwei on 6/24/14.
 */
public class Solution {

  public List<Integer> postorderTraversal(TreeNode root) {
    List<Integer> list = new LinkedList<Integer>();
    TreeNode prev = new TreeNode(0); // Dummy
    Stack<TreeNode> stack = new Stack<TreeNode>();
    stack.add(root);
    while (!stack.empty()) {
      TreeNode node = stack.pop();
      if (node != null) {
        if ((node.left == null && node.right == null) ||
            (node.right == null && prev == node.left) ||
            prev == node.right) {
          list.add(node.val);
          prev = node;
        } else {
          stack.push(node);
          stack.push(node.right);
          stack.push(node.left);
        }
      }
    }
    return list;
  }

  private enum Type {
    FIRST,
    SECOND,
    THIRD
  }

  public List<Integer> postorderTraversalTwoState(TreeNode root) {
    List<Integer> results = new LinkedList<>();
    Stack<Pair<TreeNode, Type>> stack = new Stack<>();
    if (root != null) {
      stack.push(new Pair<TreeNode, Type>(root, Type.FIRST));
    }
    while (!stack.isEmpty()) {
      Pair<TreeNode, Type> pair = stack.pop();
      TreeNode node = pair.getFirst();
      Type type = pair.getSecond();
      if (node != null) {
        switch (type) {
          case FIRST:
            stack.push(new Pair<TreeNode, Type>(node, Type.SECOND));
            if (node.left != null) {
              stack.push(new Pair<TreeNode, Type>(node.left, Type.FIRST));
            }
            break;
          case SECOND:
            stack.push(new Pair<TreeNode, Type>(node, Type.THIRD));
            if (node.right != null) {
              stack.push(new Pair<TreeNode, Type>(node.right, Type.FIRST));
            }
            break;
          case THIRD:
            results.add(node.val);
            break;
        }
      }
    }
    return results;
  }

  // Use two stacks to solve postorder traversal.
  public List<Integer> postorderTraversalTwoStack(TreeNode root) {
    Stack<TreeNode> stack = new Stack<TreeNode>();
    List<Integer> result = new LinkedList<Integer>();
    stack.push(root);
    while (!stack.empty()) {
      TreeNode node = stack.pop();
      if (node != null) {
        stack.push(node.left);
        stack.push(node.right);
        result.add(node.val);
      }
    }
    Collections.reverse(result);
    return result;
  }
}
