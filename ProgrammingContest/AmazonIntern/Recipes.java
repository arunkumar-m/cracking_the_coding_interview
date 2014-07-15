import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Recipes {

	public static void main(String[] args) {
		List<String> input = Arrays.asList("flour 1 cups", "flour 1/2 cups", "flour 1 tsp", "sugar 2 tbsp", "salt 3 cups",
				"bakingsoda 1/16 cups", "haha 1/48 cups");
		List<String> output = run(input);
		for (String line : output)
			System.out.println(line);
	}
	
	private static double convertToTsp(double amount, String unit) {
		if (unit.equals("cups")) {
			return amount * 48;
		} else if (unit.equals("tbsp")) {
			return amount * 3;
		} else {
			return amount;
		}
	}
	
	private static String getNum(double x) {
		if (x >= 48) {
			return new Double(Math.ceil(x / 48)).intValue() + " cups";
		} else if (x >= 3) {
			return new Double(Math.ceil(x / 3)).intValue() + " tbsp";
		} else {
			return new Double(Math.ceil(x)).intValue() + " tsp";
		}
	}
	
	private static List<String> toArray(Map<String, Double> stats) {
		// Sort
		List<String> names = new ArrayList<String>();
		for (String name: stats.keySet()) {
			names.add(name);
		}
		Collections.sort(names);
		List<String> results = new ArrayList<String>();
		for (String name: names) {
			results.add(name + " " + getNum(stats.get(name)));
		}
		return results;
	}

	public static List<String> run(List<String> input) {
		Map<String, Double> stats = new HashMap<String, Double>();
		// Line by line
		for (String line: input) {
			// Parse the input
			String[] strs = line.split(" ");
			String name = strs[0];
			double amount;
			if (strs[1].contains("/")) {
				String[] tmp = strs[1].split("/");
				amount = Double.parseDouble(tmp[0]) / Double.parseDouble(tmp[1]);
			} else {
				amount = Double.parseDouble(strs[1]);
			}
			String unit = strs[2];
			amount = convertToTsp(amount, unit);
			if (stats.containsKey(name)) {
				double oldValue = stats.get(name);
				stats.put(name, oldValue + amount);
			} else {
				stats.put(name, amount);
			}
		}
		return toArray(stats);
	}
}