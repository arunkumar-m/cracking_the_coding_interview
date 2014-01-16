# Strongly Connected Components

This is the solution to [Algorithms: Design and Analysis, Part
1](https://class.coursera.org/algo-004)'s 4th programming assignments.

You can use [small test
cases](https://class.coursera.org/algo-004/forum/thread?thread_id=1062) to test your answer first when doing
this programming assignment because the large
test is larger than 60MB!

## Algorithm

Kosaraju's Two-Pass Algorithm

Theorem: can compute all SCCs in O(m + n) time.

Algorithm: (given directed graph G)

1. Let G^rev = G with all arcs reversed
2. run DFS-Loop on G^rev (goal: compute "magical ordering" of nodes)
  - Let f(v) = "finishing time" of each v in V
3. run DFS-Loop on G (goal: discover the SCCs one-by-one)
  - Processing nodes in decreasing order of finishing times
[SCCs = nodes with the same "leader"]

### Code

    DFS-Loop(graph G)
    -----------------
    global variable t = 0 (for finishing times in first pass)
    [# of nodes processed so far]
    global variable s = NULL (for leaders in second pass)
    [current source vertex]
    Assume nodes labelled 1 to n
    For i = n down to 1
      if i not yet explored
        s := i
        DFS(G, i)

    DFS(graph G, node i)
    --------------------
    - mark i as explored
    - set leader(i) := node s
    - for each arc (i, j) in G:
      - if j not yet explored:
        - DFS(G, j)
    - t++
    - set f(i) := t (i's finishing time)

Running Time: 2 * DFS = O(m + n)

## Usage

Large test case can be retrieved [here](http://spark-public.s3.amazonaws.com/algo1/programming_prob/SCC.txt).

Like any .c file:

    gcc -o scc scc.c
    ./scc < SCC.txt

Using time to test the performance:

    time ./scc < SCC.txt
    Loading data ...
    Data loaded!
    Number of Nodes: 875714
    The number of SCCs in total: 371762
    434821,968,459,313,211
    ./scc < SCC.txt  2.28s user 0.12s system 99% cpu 2.410 total
