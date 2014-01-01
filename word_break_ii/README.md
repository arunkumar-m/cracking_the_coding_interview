# Word Break II

Given a string and a dictionary of words _dict_, add spaces in s to
construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given

s = "catsanddog",

dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

## Solution

2D dynamic programming + backtrack.
