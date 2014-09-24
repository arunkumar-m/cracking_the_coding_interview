package com.wwei2.leetcode.wordsearch;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/24/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test1() {
    char[][] board = new char[3][];
    board[0] = new char[]{'A', 'B', 'C', 'E'};
    board[1] = new char[]{'S', 'F', 'C', 'S'};
    board[2] = new char[]{'A', 'D', 'E', 'E'};
    Assert.assertEquals(true, sol.exist(board, "ABCCED"));
    Assert.assertEquals(true, sol.exist(board, "SEE"));
    Assert.assertEquals(false, sol.exist(board, "ABCB"));
  }
}
