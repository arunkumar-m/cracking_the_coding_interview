package com.wwei2.leetcode.wordsearch;

import com.wwei2.leetcode.util.Pair;

import java.util.HashSet;
import java.util.Set;

/**
 * Word search.
 */
public class Solution {
  public boolean exist(char[][] board, String word) {
    int length = board.length;
    int width = length == 0 ? 0 : board[0].length;
    for (int i = 0; i < length; i++) {
      for (int j = 0; j < width; j++) {
        if (dfs(board, i, j, word, 0, new HashSet<Pair<Integer, Integer>>())) {
          return true;
        }
      }
    }
    return false;
  }

  private boolean dfs(char[][] board, int i, int j, String word, int num, Set<Pair<Integer, Integer>> visited) {
    int length = board.length;
    int width = board[0].length;
    if (num == word.length()) {
      return true;
    }
    if (i < 0 || i >= length || j < 0 || j >= width ||
        visited.contains(new Pair<Integer, Integer>(i, j)) ||
        board[i][j] != word.charAt(num)) {
      return false;
    }
    visited.add(new Pair<Integer, Integer>(i, j));
    boolean success =
        dfs(board, i + 1, j, word, num + 1, visited) ||
        dfs(board, i - 1, j, word, num + 1, visited) ||
        dfs(board, i, j + 1, word, num + 1, visited) ||
        dfs(board, i, j - 1, word, num + 1, visited);
    visited.remove(new Pair<Integer, Integer>(i, j));
    return success;
  }
}
