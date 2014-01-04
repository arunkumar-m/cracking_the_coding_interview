# Dynamic Programming

## Two Motivating Applications

### Distributed Shortest Path Routing

#### Graphs and the Internet

Claim: the Internet is a graph.

[vertices = end hosts + routers, directed edges = direct physical or
wireless connections]

- web graph [vertices = webpages, edges = hyperlinks]
- social networks [vertices = people, edges = friend / follow
  relationshiops]

#### Internet Routing

Suppose: Stanford gateway router needs to send data to the Cornell
gateway router (over multiple hops)

Question: which Stanford -> Cornell route to use?

Obvious: how about the shortest? (e.g., fewest # of hops)

Recall from Part I: Dijkstra's algorithm does this (with nonnegative
edge lengths)

Issue: Stanford gateway router would need to know the entire Internet!

=> need a shortest-path algorithm that uses only local computation

Solution: the Bellman-Ford algorithm (bonus: also handles negative edge
lengths)

### Sequenece Alignment

Sequence Alignment: fundamental problem in computational genomics.

Input: two strings over the alphabet [A, C, G, T]

Problem: figure out how "similar" the two strings are

Example applications:
1. extrapolate function of genome substrings
2. similar genomes can reflect proximity in evolutionary tree

#### Measuring Similarity

Question: what does "similar" mean?

Example:

AGGGCT

AGG-CA

#### Problem Statement

Input: 2 strings over {A, C, G, T}
- penalty >= 0 for each gap
- penalty >= 0 for mismatching 

Output: alignment of the strings that minimizes the total penalty.

=> called the needleman-wunsch score [1980]

Small NW Score suggests similar strings.

#### Algorithms Are Fundamental

Note: this measure of genome similarity would be useless without an
efficient algorithm to find teh best alignment.

Brute-force Search: try all possible alignments, remember the best.

Question: suppose each string has length 500. Roughly how many possible
alignments are there?

- number of students in this class 10^4 - 10^5
- number of people on earth 10^9 - 10^10
- number of atoms in know universe 10^80
- more than any of the above 2^500 >= 10^125

The correct answer is "more than any of the above"!

Point: need a fast clever algorithm.

Solution: straightforward dynamic programming.
