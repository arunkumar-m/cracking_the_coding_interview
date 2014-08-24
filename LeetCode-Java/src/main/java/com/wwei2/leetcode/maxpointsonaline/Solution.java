package com.wwei2.leetcode.maxpointsonaline;

import com.wwei2.leetcode.util.Point;

import java.util.HashMap;
import java.util.Map;

/**
 * Max points on a line.
 */
public class Solution {
  private void incrementCount(Map<Double, Integer> map, Double d) {
    if (map.containsKey(d)) {
      map.put(d, map.get(d) + 1);
    } else {
      map.put(d, 1);
    }
  }
  private int getMaxCount(Map<Double, Integer> map) {
    int maxSoFar = 0;
    for (Map.Entry<Double, Integer> entry : map.entrySet()) {
      if (entry.getValue() > maxSoFar) {
        maxSoFar = entry.getValue();
      }
    }
    return maxSoFar;
  }
  public int maxPoints(Point[] points) {
    if (points.length == 0) {
      return 0;
    }
    int maxSoFar = 0;
    for (int i = 0; i < points.length; i++) {
      Map<Double, Integer> map = new HashMap<>();
      int samePoints = 0;
      for (int j = 0; j < points.length; j++) {
        if (i != j) {
          Point x = points[i];
          Point y = points[j];
          if (x.x == y.x) {
            if (x.y == y.y) {
              samePoints += 1;
            } else {
              incrementCount(map, Double.POSITIVE_INFINITY);
            }
          } else {
            incrementCount(map, ((double)(x.y - y.y) / (x.x - y.x)));
          }
        }
      }
      int count = getMaxCount(map);
      if (count + samePoints > maxSoFar) {
        maxSoFar = count + samePoints;
      }
    }
    return maxSoFar + 1;
  }
}
