# Word Ladder II

Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time

Each intermediate word must exist in the dictionary

For example,

Given:

start = "hit"

end = "cog"

dict = ["hot","dot","dog","lot","log"]

Return

    [
      ["hit","hot","dot","dog","cog"],
      ["hit","hot","lot","log","cog"]
    ]

**Note:**

All words have the same length.

All words contain only lowercase alphabetic characters.

## Solution

Use BFS to find the shortest path and use DFS to backtrack. Can pass
small judge but fail big judge. Need more elaborate optimizations.

**Use an extra _prev_ variable to construct the paths and pass the large
judge finally!**
