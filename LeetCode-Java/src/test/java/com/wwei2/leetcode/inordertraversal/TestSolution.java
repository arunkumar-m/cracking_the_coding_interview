package com.wwei2.leetcode.inordertraversal;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;
import java.util.List;

/**
 * Created by weiwei on 8/5/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall() {
    TreeNode root = new TreeNode(2);
    root.left = new TreeNode(1);
    root.right = new TreeNode(3);
    List<Integer> results = sol.inorderTraversal(root);
    Assert.assertTrue(results.equals(Arrays.asList(1, 2, 3)));
  }
}
