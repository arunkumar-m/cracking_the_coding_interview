package com.wwei2.leetcode.levelordertraversal;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;
import java.util.List;

/**
 * Created by weiwei on 7/25/14.
 */
public class TestSolution {

  private Solution sol = new Solution();

  @Test
  public void TestSimple() {
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    List<List<Integer>> results = sol.levelOrder(root);
    System.out.println(results);
    root.left.left = new TreeNode(4);
    root.right.right = new TreeNode(5);
    root.right.right.right = new TreeNode(6);
    results = sol.levelOrder(root);
    System.out.println(results);
  }
}
