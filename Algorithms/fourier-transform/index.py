def getIdx(col, m):
    y = col % m
    x = col / m
    return  2 * m * x + y

m = [1, 2, 4]

for i in range(3):
    for col in range(4):
        print getIdx(col, m[i]),
    print
