# Python Implementation for Dijkstra's Algorithm

def readData(adj, dist):
    print "Loading Data ..."
    f = open('dijkstraData.txt', 'r')
    for line in f.readlines():
        line = line.split()
        node = int(line[0])
        for i in line[1:]:
            i = i.split(',')
            dist[(node, int(i[0]))] = int(i[1])
            if node in adj.keys():
                adj[node].append(int(i[0]))
            else:
                adj[node] = [int(i[0])]
    print "Data loaded."

# dijkstra's algorithm without using a heap
# time complexity O(mn) where m is the number of edges and n is the number of vertices
def dijkstra(src, adj, dist):
    n = len(adj) # number of vertices
    X = [src] # vertices that have been explored
    V = adj.keys() # all the vertices
    A = list([0xFFFFFF] *  (n + 1)) # A[i] keep track of smallest dist between src and i
    A[src] = 0
    B = {} # B[i] keep track of the shortest path between src and i
    B[src] = []

    while len(X) != n: # while X != V, add one vertices to X each iteration
        minLen = 0xFFFFFFFF
        edge = []
        for key in dist.keys(): 
            if key[0] in X and key[1] not in X: # if this edge is crossing frontier
                if minLen > dist[key] + A[key[0]]: # dijkstra's greedy criterion
                    minLen = dist[key] + A[key[0]]
                    edge = key
        X.append(edge[1]) # expanding X
        A[edge[1]] = A[edge[0]] + dist[edge] # update A
        B[edge[1]] = B[edge[0]] + [edge[1]] # update B

    # answers
    print A[7], A[37], A[59], A[82], A[99], A[115], A[133], A[165], A[188], A[197]



def main():
    # load data
    adj = {}
    dist = {}
    readData(adj, dist)
    # call dijkstra's algorithm
    dijkstra(1, adj, dist)

if __name__ == '__main__':
    main()
