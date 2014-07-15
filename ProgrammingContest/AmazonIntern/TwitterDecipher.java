import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class TwitterDecipher {

	public static void main(String[] args) {
		// Test expandable
		System.out.println(expandable("fn", "fun"));
		System.out.println(expandable("jst", "just"));
		System.out.println(expandable("jst", "joust"));
		System.out.println(expandable("cntst", "contest"));
		System.out.println(expandable("ownd", "owned"));
		// This method is provided purely for testing. It will not be called by the
		// contest server.
		String mapping = "2 to u you 4 for w with";
		String dictionary = "contest just joust owned programming friend fun";
		String tweet = "I jst ownd the progming cntst 4 @amazon... so fn! #YOLO";
		System.out.println(run(mapping, dictionary, tweet));
	}
	
	private static int getPuncIndex(String word) {
		int length = word.length();
		int index = length;
		for (int i = length - 1; i >= 0; i--) {
			if (!Character.isAlphabetic(word.charAt(i))) {
				index = i;
			} else {
				break;
			}
		}
		return index;
	}
	
	private static boolean expandable(String word, String dictWord) {
		if (word.isEmpty()) return true;
		if (dictWord.isEmpty()) return false;
		if (word.charAt(0) == dictWord.charAt(0)) {
			return expandable(word.substring(1), dictWord.substring(1));
		} else {
			return expandable(word, dictWord.substring(1));
		}
	}

	public static String run(String mapping, String dictionary, String tweet) {
		// Get one to one mapping
		String[] mappings = mapping.split(" ");
		Map<String, String> map = new HashMap<String, String>();
		for (int i = 0; i < mappings.length; i += 2) {
			map.put(mappings[i], mappings[i + 1]);
		}

		// Get dictionary
		Set<String> dict = new HashSet<String>();
		String[] strs = dictionary.split(" ");
		for (String str: strs) {
			dict.add(str);
		}

		// Split tweet
		String[] words = tweet.split("\\s+");
		List<String> candidates = new ArrayList<String>();

		// Process
		for (String word: words) {
			// @ || #
			if (word.startsWith("@") || word.startsWith("#")) {
				candidates.add(word);
				continue;
			}
			// one to one mapping
			if (map.containsKey(word)) {
				candidates.add(map.get(word));
				continue;
			}
			// preserve punctuations
			int index = getPuncIndex(word);
			String punc = word.substring(index);
			String w = word.substring(0, index);
			// System.out.println(w + " " + punc);
			// expand dictionary words,  more than one possibility, don't convert.
			List<String> cands = new ArrayList<String>();
			for (String s: dict) {
				if (expandable(w, s)) {
					cands.add(s);
				}
			}
			if (cands.size() == 1) {
				candidates.add(cands.get(0) + punc);
			} else {
				candidates.add(word);
			}
		}
		StringBuilder result = new StringBuilder();
		result.append(candidates.get(0));
		for (int i = 1; i < candidates.size(); i++) {
			result.append(" " + candidates.get(i));
		}
		return result.toString();
	}
}