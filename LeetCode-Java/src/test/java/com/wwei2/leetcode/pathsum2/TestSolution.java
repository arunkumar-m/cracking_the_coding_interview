package com.wwei2.leetcode.pathsum2;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Test;

/**
 * Created by weiwei on 9/20/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test1() {
    TreeNode root = new TreeNode(5);
    root.left = new TreeNode(4);
    root.right = new TreeNode(8);
    root.left.left = new TreeNode(11);
    root.left.left.left = new TreeNode(7);
    root.left.left.right = new TreeNode(2);
    root.right.left = new TreeNode(13);
    root.right.right = new TreeNode(4);
    root.right.right.left = new TreeNode(5);
    root.right.right.right = new TreeNode(1);
    System.out.println(sol.pathSum(root, 22));
  }
}
