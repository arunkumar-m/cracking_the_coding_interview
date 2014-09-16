package com.wwei2.leetcode.wordladder;

import com.wwei2.leetcode.util.Pair;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

/**
 * Word ladder. BFS.
 */
public class Solution {
  public int ladderLength(String start, String end, Set<String> dict) {
    Queue<Pair<String, Integer>> queue = new LinkedList<>();
    queue.add(new Pair<String, Integer>(start, 1));
    Set<String> visited = new HashSet<>();
    while (!queue.isEmpty()) {
      Pair<String, Integer> pair = queue.remove();
      String word = pair.getFirst();
      int dist = pair.getSecond();
      if (!visited.contains(word)) {
        visited.add(word);
        for (int i = 0; i < word.length(); i++) {
          for (int j = 0; j < 26; j++) {
            String neighbor = word.substring(0, i) + (char)(97 + j) + word.substring(i + 1);
            if (neighbor.equals(end)) {
              return dist + 1;
            }
            if (dict.contains(neighbor)) {
              queue.add(new Pair<String, Integer>(neighbor, dist + 1));
            }
          }
        }
      }
    }
    return 0;
  }
}
