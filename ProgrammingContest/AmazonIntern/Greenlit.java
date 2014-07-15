import java.util.Arrays;
import java.util.List;

public class Greenlit {

  public static void main(String[] args) {
    // This method is provided purely for testing. It will not be called by the
    // grading robot.
    System.out.println(run(Arrays.asList(2.99d, 3.99d, .299d, 10d), Arrays.asList(100, 70, 1000, 25)));
  }

  public static double run(List<Double> prices, List<Integer> demand) {
    // Write your code in this method, without changing the signature.
	int length = prices.size();
	double maxSoFar = 0;
	double price = Double.POSITIVE_INFINITY;
	for (int i = 0; i < length; i++) {
		double total = prices.get(i) * demand.get(i);
		if (total > maxSoFar) {
			price = prices.get(i);
			maxSoFar = total;
		} else if (total == maxSoFar && prices.get(i) < price) {
			price = prices.get(i);
			maxSoFar = total;
		}
	}
	return price;
  }
}