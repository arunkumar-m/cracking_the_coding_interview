package com.wwei2.leetcode.surroundedregions;

import com.wwei2.leetcode.util.Pair;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 */
public class Solution {
  private int height, width;
  private boolean[][] visited;
  private char[][] myBoard;
  public void solve(char[][] board) {
    myBoard = board;
    height = board.length;
    if (height == 0) {
      return;
    }
    width = board[0].length;
    visited = new boolean[height][width];
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        visited[i][j] = false;
      }
    }
    for (int i = 0; i < width; i++) {
      visit(0, i);
      visit(height - 1, i);
    }
    for (int i = 0; i < height; i++) {
      visit(i, 0);
      visit(i, width - 1);
    }
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (!visited[i][j]) {
          board[i][j] = 'X';
        }
      }
    }
  }
  private void visit(int i, int j) {
    Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
    queue.add(new Pair<Integer, Integer>(i, j));
    while (!queue.isEmpty()) {
      Pair<Integer, Integer> pair = queue.remove();
      int r = pair.getFirst();
      int c = pair.getSecond();
      if ((r < 0 || r >= height || c < 0 || c >= width) ||
          visited[r][c] ||
          myBoard[r][c] != 'O') {
        continue;
      }
      visited[r][c] = true;
      queue.add(new Pair<Integer, Integer>(r - 1, c));
      queue.add(new Pair<Integer, Integer>(r + 1, c));
      queue.add(new Pair<Integer, Integer>(r, c - 1));
      queue.add(new Pair<Integer, Integer>(r, c + 1));
    }
  }
}
