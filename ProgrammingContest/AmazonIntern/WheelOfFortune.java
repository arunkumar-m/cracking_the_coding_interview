import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class WheelOfFortune {

	public static void main(String[] args) {
		// This method is provided purely for testing. It will not be called by the
		// contest server.
		System.out.println(run("L___", Arrays.asList("LOVE", "LAVA", "LAMP")));
		System.out.println(run("__EE _I__A", Arrays.asList("FREE PIZZA", "GOOD PIZZA", "TREE NINJA", "FLEE VISTA", "CAPTAIN OBVIOUSLY WRONG ANSWER")));
		System.out.println(run("L___", Arrays.asList("AAAA", "BBBB", "CCCC")));
		System.out.println(run("A____", Arrays.asList("AAAAA", "ABBBB", "ACCCC")));
	}
	
	private static boolean compare(String x, String y) {
		int length = x.length();
		for (int i = 0; i < length; i++) {
			char a = x.charAt(i);
			char b = y.charAt(i);
			if (a != '_' && a != b)
				return false;
		}
		return true;
	}
	
	private static Set<String> getResult(String x, String y) {
		int length = x.length();
		Set<String> set = new HashSet<String>();
		for (int i = 0; i < length; i++) {
			Character a = x.charAt(i);
			Character b = y.charAt(i);
			if (a.equals('_')) {
				set.add(b.toString());
			}
		}
		return set;
	}

	public static String run(String currentState, List<String> dictionary) {
		Set<String> currentChars = new HashSet<String>();
		for (int i = 0; i < currentState.length(); i++) {
			currentChars.add(new Character(currentState.charAt(0)).toString());
		}
		List<String> candidates = new ArrayList<String>();
		for (String phrase: dictionary) {
			if (currentState.length() == phrase.length()) {
				if (compare(currentState, phrase))
					candidates.add(phrase);
			}
		}
		if (candidates.isEmpty()) {
			return "No letters";
		} else {
			Set<String> result = new HashSet<String>();
			for (String s: candidates) {
				Set<String> tmp = getResult(currentState, s);
				Set<String> tst = new HashSet<String>(tmp);
				tst.retainAll(currentChars);
				if (tst.isEmpty())
					result.addAll(tmp);
			}
			List<String> list = new ArrayList<String>();
			for (String s: result) {
				list.add(s);
			}
			Collections.sort(list);
			StringBuilder finalResult = new StringBuilder();
			for (String s: list) {
				finalResult.append(s);
			}
			return finalResult.toString();
		}
	}
}