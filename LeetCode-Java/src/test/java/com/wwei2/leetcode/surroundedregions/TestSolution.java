package com.wwei2.leetcode.surroundedregions;

import org.junit.Test;

/**
 * Created by weiwei on 9/15/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall() {
    char[][] board = createBoard("XXXXXOOXXXOXXOXX", 4, 4);
    sol.solve(board);
    printBoard(board);
  }
  private void printBoard(char[][] board) {
    int h = board.length;
    int w = board[0].length;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        System.out.print(board[i][j] + " ");
      }
      System.out.println("");
    }
  }
  private char[][] createBoard(String s, int h, int w) {
    char[][] board = new char[h][w];
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        board[i][j] = s.charAt(i * w + j);
      }
    }
    return board;
  }
}
