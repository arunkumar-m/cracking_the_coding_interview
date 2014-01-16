"""
Prim's Minimum Spanning Tree Algorithm
"""

from heapq import *

def loadData(filename = "edges.txt"):
    with open(filename, "r") as f:
        lines = f.readlines()
        num_nodes, num_edges = map(int, lines[0].split())
        lines = lines[1:]
        adj = {x: [] for x in range(1, num_nodes + 1)}
        edges = {}
        for line in lines:
            line = map(int, line.strip().split(' '))
            edges[(line[0], line[1])] = line[2]
            edges[(line[1], line[0])] = line[2]
            adj[line[0]].append(line[1])
            adj[line[1]].append(line[0])
        return adj, edges

def createHeap(num_nodes):
    entry_finder = {i: [0x7FFFFFFF, i] for i in range(1, num_nodes + 1)}
    heap = entry_finder.values()
    heap[0][0] = 0
    heapify(heap)
    return heap, entry_finder

def prim():
    adj, edges = loadData()
    heap, vertex_finder = createHeap(len(adj))
    X = set([])
    V = set(adj.keys())
    cost = 0
    while len(X) != len(V):
        dist, v = heappop(heap)
        cost += dist # update cost
        X.add(v) # update X
        # update element
        for neighbor in adj[v]:
            if neighbor not in X:
                entry = vertex_finder[neighbor]
                entry[0] = min(edges[(v, neighbor)], entry[0])
        heapify(heap)
    print "MST:", cost

if __name__ == '__main__':
    prim()
