package com.wwei2.leetcode.zigzaglevelordertraversal;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Test;

import java.util.List;

/**
 * Created by weiwei on 8/1/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall() {
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    List<List<Integer>> results = sol.zigzagLevelOrder(root);
    print2DList(results);
  }
  @Test
  public void testMid() {
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left.left = new TreeNode(4);
    root.left.right = new TreeNode(5);
    root.right.right = new TreeNode(6);
    root.left.left.right = new TreeNode(7);
    root.right.right.right = new TreeNode(8);
    List<List<Integer>> results = sol.zigzagLevelOrder(root);
    print2DList(results);
  }

  private void print2DList(List<List<Integer>> results) {
    System.out.println("## Print 2D list.");
    for (List<Integer> list : results) {
      for (Integer i : list) {
        System.out.print(i + " ");
      }
      System.out.println("");
    }
    System.out.println("");
  }
}
