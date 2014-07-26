package com.wwei2.leetcode.levelordertraversal2;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Test;

import java.util.List;

/**
 * Created by weiwei on 7/26/14.
 */
public class TestSolution {

  private Solution sol = new Solution();

  @Test
  public void TestSimple() {
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    List<List<Integer>> results = sol.levelOrderBottom(root);
    System.out.println(results);
    root.left.left = new TreeNode(4);
    root.right.right = new TreeNode(5);
    root.right.right.right = new TreeNode(6);
    results = sol.levelOrderBottom(root);
    System.out.println(results);
  }
}
