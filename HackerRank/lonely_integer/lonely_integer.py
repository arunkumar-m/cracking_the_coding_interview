"""
Lonely Integer
"""

def lonelyinteger(a):
    count = {}
    for i in a:
        if i in count.keys():
            count[i] += 1
        else:
            count[i] = 1

    for k in count.keys():
        if count[k] == 1:
            return k

if __name__ == '__main__':
    a = input()
    b = map(int, raw_input().strip().split(" "))
    print lonelyinteger(b)
