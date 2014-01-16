## an implementation for random contraction algorithm

from copy import deepcopy
from random import randint # randint(x, y) generates a random integer from 1 to 10, endpoints included

## helper functions defined here

def pickEdge(edge):
    rand = randint(0, len(edge) - 1)
    e = edge[rand]
    return e[0], e[1]

def merge(u, v, edge):
    for e in edge:
        if e[0] == v:
            e[0] = u
        if e[1] == v:
            e[1] = u

def removeSelfLoop(edge):
    return [e for e in edge if e[0] != e[1]]

def countEdges(edge):
    return len(edge)

print "Loading Data ..."
lines = open('kargerMinCut.txt', 'r').readlines()
# lines = open('small.txt', 'r').readlines()
n = len(lines)
print "Data loaded."

## initialization

# adj = [[0 for i in range(n + 1)] for j in range(n + 1)] # use list comprehension to generate 2d array
# adj = {} # adjcency list

edge = [] # use a set to store all edges

for line in lines:
    line = map(int, line.split())
    v = line[0]
    # adj[v] = set([])
    for vi in line[1:]:
        # adj[v].add(vi)
        if v < vi:
            edge.append([v, vi])

print edge

## random contraction algorithm

min_cut = 0xFFFFFFFF # keep track of the minimum cut so far

for i in range(n * n): # remember that? if we iterate n^2 times, the probability to fail is 1 / e!
    cnt = n
    curr = deepcopy(edge)
    while cnt > 2:
        u, v = pickEdge(curr) # pick a remaining edge (u, v) uniformly at random
        merge(u, v, curr) # merge u and v into a single vertex and remove self loops
        curr = removeSelfLoop(curr)
        cnt -= 1
    edge_cnt = countEdges(curr)
    print "####"
    print curr
    print i, min_cut, edge_cnt
    print "####"
    min_cut = min(min_cut, edge_cnt)

print "ANSWER:", min_cut
