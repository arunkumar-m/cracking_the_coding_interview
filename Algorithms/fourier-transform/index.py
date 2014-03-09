def getIdx(col, m, j):
    y = col % m
    x = (col - y) / j
    return 2 * m * x + y

m = [1, 2, 4]
j = [4, 2, 1]

for i in range(3):
    for col in range(4):
        print getIdx(col, m[i], j[i]),
    print
