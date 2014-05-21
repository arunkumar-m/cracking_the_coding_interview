import java.util.*;

public class twoSum {
  public static int[] twoSum(int[] numbers, int target) {
    Map<Integer, Integer> m = new HashMap<Integer, Integer>();
    int[] ret = new int[2];
    for (int i = 0; i < numbers.length; i++) {
      if (m.containsKey(target - numbers[i])) {
        ret[0] = m.get(target - numbers[i]) + 1;
        ret[1] = i + 1;
        if (m.get(target - numbers[i]) < i) {
          return ret;
        }
      } else if (!m.containsKey(numbers[i])) {
        m.put(numbers[i], i);
      }
    }
    return ret;
  }

  public static void main(String[] args) {
    int[] arr = new int[3];
    arr[0] = 3;
    arr[1] = 2;
    arr[2] = 4;
    int[] ret = twoSum(arr, 6);
    System.out.println(ret[0]);
    System.out.println(ret[1]);
  }
}
