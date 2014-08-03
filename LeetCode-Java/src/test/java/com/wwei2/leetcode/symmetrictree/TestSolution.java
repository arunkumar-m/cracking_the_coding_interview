package com.wwei2.leetcode.symmetrictree;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 8/1/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall() {
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(2);
    root.left.left = new TreeNode(3);
    root.right.right = new TreeNode(3);
    root.left.right = new TreeNode(4);
    root.right.left = new TreeNode(4);
    Assert.assertEquals(true, sol.isSymmetric(root));
  }

  @Test
  public void testNonSymmetricTree() {
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(2);
    root.left.right = new TreeNode(3);
    root.right.right = new TreeNode(3);
    Assert.assertEquals(false, sol.isSymmetric(root));
  }
}
