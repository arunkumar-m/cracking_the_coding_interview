# Rain Fall

"""
read data from input
"""
def readData():
    num = input()
    data = []
    for i in range(num):
        data.append(map(int, raw_input().strip().split(" ")))
    return data

"""
create a undirected graph from data
"""
def createGraph(data):
    size = len(data)
    # initialize the graph
    graph = {(i, j) : [] for i in range(size) for j in range(size)}
    """
    iterate through all the cell to create a graph
    """
    for i in range(size):
        for j in range(size):
            minx, miny, minvalue = i, j, data[i][j]
            """
            iterate through all (i, j)'s neighbors and find the lowest
            """
            for ii in range(i - 1, i + 2):
                for jj in range(j - 1, j + 2):
                    if ii >= 0 and jj >= 0 and ii < size and jj < size:
                        if data[ii][jj] < minvalue:
                            minvalue = data[ii][jj]
                            minx = ii
                            miny = jj
            if minx != i or miny != j:
                graph[(i, j)].append((minx, miny))
                graph[(minx, miny)].append((i, j))
    return graph

"""
perform depth-first search on the given graph
"""
def dfs_loop(graph):
    # use explored to keep track of the cell we have visited
    visited = {key : 0 for key in graph.keys()}
    basin = {key : 0 for key in graph.keys()}
    label = 0
    for vertex in graph.keys():
        if visited[vertex] == 0:
            dfs(vertex, graph, visited, basin, label)
            label += 1
    return basin, label

"""
perform depth-first search on a given node
"""
def dfs(vertex, graph, visited, basin, label):
    # use stack to simulate recursive calls
    stack = []
    stack.append(vertex)
    while len(stack) != 0:
        v = stack.pop()
        visited[v] = 1
        basin[v] = label
        for neighbor in graph[v]:
            if visited[neighbor] == 0:
                stack.append(neighbor)

"""
count the number of basin found, return the size in decreasing order
"""
def countBasinSize(basin, numBasin):
    count = [0 for x in xrange(numBasin)]
    for pos in basin.keys():
        count[basin[pos]] += 1
    return sorted(count, reverse=True)

"""
display basin
"""
def printBasin(basin, size):
    mat = [[0 for x in xrange(size)] for x in xrange(size)]
    for (x, y) in basin:
        mat[x][y] = basin[(x, y)]
    for i in xrange(size):
        for j in xrange(size):
            print mat[i][j],
        print

# main
if __name__ == '__main__':
    data = readData()
    graph = createGraph(data)
    basin, numBasin = dfs_loop(graph)
    # printBasin(basin, len(data))
    output = countBasinSize(basin, numBasin)
    print "".join([str(i) + ' ' for i in output])
