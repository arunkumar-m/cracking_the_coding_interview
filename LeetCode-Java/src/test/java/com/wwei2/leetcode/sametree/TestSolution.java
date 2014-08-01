package com.wwei2.leetcode.sametree;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 8/1/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  
  @Test
  public void testSmallTree() {
    TreeNode root1 = new TreeNode(1);
    root1.left = new TreeNode(2);
    root1.right = new TreeNode(3);
    TreeNode root2 = new TreeNode(1);
    root2.left = new TreeNode(2);
    root2.right = new TreeNode(3);
    Assert.assertEquals(true, sol.isSameTree(root1, root2));
  } 
}
