# generate permutations

def perm(x):
    if len(x) == 1:
        return [x]
    y = perm(x[1:])
    fst = x[0]
    ret = []
    for i in range(len(y)):
        for j in range(len(y[i]) + 1):
            ret.append(y[i][:j] + [fst] + y[i][j:])
    return ret

if __name__ == '__main__':
    print len(perm([1,2,3,4,5]))
    print len(perm([1,2,3]))
