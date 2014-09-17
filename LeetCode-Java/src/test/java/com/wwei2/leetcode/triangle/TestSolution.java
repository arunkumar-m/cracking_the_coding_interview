package com.wwei2.leetcode.triangle;

import org.junit.Assert;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by weiwei on 9/16/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall() {
    List<List<Integer>> triangle = new ArrayList<List<Integer>>() {{
      add(new ArrayList<Integer>(){{ add(2); }});
      add(new ArrayList<Integer>(){{ add(3); add(4); }});
      add(new ArrayList<Integer>(){{ add(6); add(5); add(7); }});
      add(new ArrayList<Integer>() {{
        add(4);
        add(1);
        add(8);
        add(3);
      }});
    }};
    Assert.assertEquals(11, sol.minimumTotal(triangle));
  }
}
