package com.wwei2.leetcode.maxpointsonaline;

import com.wwei2.leetcode.util.Point;
import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

/**
 * Created by weiwei on 8/23/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSingle() {
    Point[] points = fromList(Arrays.asList(0, 0));
    testHelper(points, 1);
  }
  @Test
  public void testThreePoints() {
    Point[] points = fromList(Arrays.asList(0, 0, 1, 1, 2, 2));
    testHelper(points, 3);
  }
  @Test
  public void testFourPoints() {
    Point[] points = fromList(Arrays.asList(0, 0, 1, 2, 3, 3, 4, 4));
    testHelper(points, 3);
    points = fromList(Arrays.asList(1, 1, 1, 1, 2, 2, 2, 2));
    testHelper(points, 4);
  }
  @Test
  public void testFivePoints() {
    Point[] points = fromList(Arrays.asList(0, 0, 1, 1, 2, 2, 4, 4, 5, 6));
    testHelper(points, 4);
  }
  @Test
  public void testVerticalLine() {
    Point[] points = fromList(Arrays.asList(0, 0, 0, 2, 0, 3, 0, 4, 5, 5, 4, 4, 3, 4));
    testHelper(points, 4);
  }
  private void testHelper(Point[] points, int expected) {
    int actual = sol.maxPoints(points);
    Assert.assertEquals(expected, actual);
  }
  private Point[] fromList(List<Integer> list) {
    int size = list.size();
    if (size % 2 != 0) {
      throw new IllegalArgumentException("The size of the list should be multiples of 2.");
    }
    Point[] points = new Point[size / 2];
    for (int i = 0; i < size; i += 2) {
      int x = list.get(i);
      int y = list.get(i + 1);
      points[i / 2] = new Point(x, y);
    }
    return points;
  }
}
