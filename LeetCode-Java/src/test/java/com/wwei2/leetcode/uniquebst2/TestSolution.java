package com.wwei2.leetcode.uniquebst2;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Test;

import java.util.List;

/**
 * Created by weiwei on 8/7/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall() {
    List<TreeNode> results = sol.generateTrees(3);
    for (TreeNode result : results) {
      System.out.println(result);
    }
  }
}
