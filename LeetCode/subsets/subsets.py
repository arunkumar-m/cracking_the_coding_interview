# generate subsets

def subsets(x):
    if len(x) == 1:
        ret = [[], x]
        return ret
    y = subsets(x[1:])
    ret = []
    for i in y:
        ret.append(i + [x[0]])
        ret.append(i)
    return ret

if __name__ == '__main__':
    print len(subsets([1,2,3,4,5]))
    print len(subsets([1,2,3]))
