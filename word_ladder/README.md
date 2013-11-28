# Word Ladder

Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

- Only one letter can be changed at a time
- Each intermediate word must exist in the dictionary

For example,

Given:
start = _"hit"_
end = _"cog"_
dict = _["hot","dot","dog","lot","log"]_
As one shortest transformation is _"hit" -> "hot" -> "dot" -> "dog" -> "cog"_,
return its length _5_.

*Note:*
- Return 0 if there is no such transformation sequence.
- All words have the same length.
- All words contain only lowercase alphabetic characters.

## Solution

Use BFS to solve this problem.

If we represented this problem as a graph where string _a_ and string
_b_ in the dictionary are neighbors if _a_ can be transformed to _b_
by changing only one letter.

One thing to note is that *do not compare each leeter of the word with the words in dict whose time complexity is O(m * n) where m is the length of the word and n is the number of words in dict*.
