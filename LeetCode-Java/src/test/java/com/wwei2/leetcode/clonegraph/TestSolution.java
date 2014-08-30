package com.wwei2.leetcode.clonegraph;

import com.wwei2.leetcode.util.UndirectedGraphNode;
import org.junit.Test;

import java.util.*;

/**
 * Created by weiwei on 9/14/14.
 */
public class TestSolution {
  private Solution sol = new Solution();

  @Test
  public void testSimple() {
    UndirectedGraphNode node = constructNodeFromString("0,1,2#1,0,2#2,0,1,2", 0);
    System.out.println("Original");
    printNode(node);
    UndirectedGraphNode copy = sol.cloneGraph(node);
    System.out.println("Copy");
    printNode(copy);
  }

  private void printNode(UndirectedGraphNode node) {
    Set<Integer> visited = new HashSet<>();
    Queue<UndirectedGraphNode> queue = new LinkedList<UndirectedGraphNode>();
    queue.add(node);
    while (!queue.isEmpty()) {
      UndirectedGraphNode curr = queue.remove();
      if (!visited.contains(curr.label)) {
        System.out.println(curr);
        for (UndirectedGraphNode neighbor : curr.neighbors) {
          queue.add(neighbor);
        }
        visited.add(curr.label);
      }
    }

  }

  private UndirectedGraphNode constructNodeFromString(String input, int start) {
    String[] parts = input.split("#");
    Map<Integer, UndirectedGraphNode> mapping = new HashMap<>();
    for (String part : parts) {
      String[] tokens = part.split(",");
      int label = Integer.parseInt(tokens[0]);
      UndirectedGraphNode curr;
      if (mapping.containsKey(label)) {
        curr = mapping.get(label);
      } else {
        curr = new UndirectedGraphNode(label);
        mapping.put(label, curr);
      }
      for (int i = 1; i < tokens.length; i++) {
        label = Integer.parseInt(tokens[i]);
        UndirectedGraphNode neighbor;
        if (mapping.containsKey(label)) {
          neighbor = mapping.get(label);
        } else {
          neighbor = new UndirectedGraphNode(label);
          mapping.put(label, neighbor);
        }
        curr.neighbors.add(neighbor);
      }
    }
    return mapping.get(start);
  }
}
