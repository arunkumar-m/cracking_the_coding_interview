# convert x in base 10 to a given base
def conv(x, base):
    ret = []
    while x >= base:
        ret.append(x % base)
        x /= base
    ret.append(x)
    ret.reverse()
    return int("".join([str(i) for i in ret]))

if __name__ == '__main__':
    print conv(10, 8)
    print conv(10, 2)
    print conv(20, 16)
