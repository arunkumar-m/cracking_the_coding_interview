package com.wwei2.leetcode.recoverbst;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 8/3/14.
 */
public class TestSolution {
  private Solution sol = new Solution();

  @Test
  public void testTwoNodes() {
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    sol.recoverTree(root);
    System.out.println(root);
    Assert.assertEquals(true, isBst(root));
  }

  @Test
  public void testSmall() {
    TreeNode root = new TreeNode(2);
    root.left = new TreeNode(3);
    root.right = new TreeNode(1);
    sol.recoverTree(root);
    System.out.println(root);
    Assert.assertEquals(true, isBst(root));
  }

  @Test
  public void testMid() {
    TreeNode root = new TreeNode(10);
    root.left = new TreeNode(15);
    root.left.left = new TreeNode(0);
    root.left.right = new TreeNode(7);
    root.right = new TreeNode(5);
    root.right.left = new TreeNode(12);
    root.right.right = new TreeNode(20);
    sol.recoverTree(root);
    System.out.println(root);
    Assert.assertEquals(true, isBst(root));
  }

  private boolean isBst(TreeNode root) {
    return isBstHelper(root, new TreeNode(Integer.MIN_VALUE));
  }
  private boolean isBstHelper(TreeNode root, TreeNode prev) {
    if (root == null) {
      return true;
    } else {
      boolean b1 = isBstHelper(root.left, prev);
      if (!b1 || root.val < prev.val) {
        return false;
      }
      prev = root;
      return isBstHelper(root.right, prev);
    }
  }
}
