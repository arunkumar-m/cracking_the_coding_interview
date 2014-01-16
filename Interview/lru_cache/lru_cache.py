class LRU_Cache:
    def __init__(self, maxsize = 10):
        self.maxsize = maxsize
        PREV, NEXT, KEY, VALUE = 0, 1, 2, 3
        self.head = [None, None, None, None] # newest
        self.tail = [self.head, None, None, None] # oldest
        self.head[NEXT] = self.tail
        self.mapping = {}

    def set(self, key, value):
        PREV, NEXT, KEY, VALUE = 0, 1, 2, 3
        head, tail = self.head, self.tail
        node = self.mapping.get(key)
        # not found
        if node is None:
            if len(self.mapping) >= self.maxsize:
                # delete tail
                last = tail[PREV]
                last[PREV][NEXT] = tail
                tail[PREV] = last[PREV]
                del self.mapping[last[KEY]]
            first = head[NEXT]
            self.mapping[key] = first[PREV] = head[NEXT] = [head, first, key, value]
        # found
        else:
            # delete
            node[PREV][NEXT] = node[NEXT]
            node[NEXT][PREV] = node[PREV]
            # insert to the front of the list
            first = head[NEXT]
            first[PREV] = head[NEXT] = node
            node[PREV] = head
            node[NEXT] = first
            node[VALUE] = value

    def get(self, key):
        PREV, NEXT, KEY, VALUE = 0, 1, 2, 3
        head = self.head
        node = self.mapping.get(key)
        # miss
        if node is None:
            print "NULL"
        # hit
        else:
            # delete node
            node[PREV][NEXT] = node[NEXT]
            node[NEXT][PREV] = node[PREV]
            # insert it to the head
            first = head[NEXT]
            first[PREV] = head[NEXT] = node
            node[PREV] = head
            node[NEXT] = first
            print node[VALUE]

    def peek(self, key):
        PREV, NEXT, KEY, VALUE = 0, 1, 2, 3
        node = self.mapping.get(key)
        # miss
        if node is None:
            print "NULL"
        # hit
        else:
            print node[VALUE]

    def dump(self):
        VALUE = 3
        for k in sorted(self.mapping.keys()):
            print k, self.mapping[k][VALUE]

    def bound(self, size):
        PREV, NEXT, KEY, VALUE = 0, 1, 2, 3
        self.maxsize = size
        node = self.head
        if size < len(self.mapping):
            node = self.head
            cnt = 0
            while node is not None:
                node = node[NEXT]
                cnt += 1
                if cnt == size:
                    break
            next_node = node[NEXT]
            node[NEXT] = self.tail
            self.tail[PREV] = node

            node = next_node
            while node is not self.tail:
                next_node = node[NEXT]
                del self.mapping[node[KEY]]
                del node
                node = next_node


# main
if __name__ == '__main__':
    cache = LRU_Cache()
    N = int(raw_input())
    for i in xrange(N):
        command = raw_input()
        command = command.strip().split(' ', 2)
        if 'BOUND' in command:
            cache.bound(int(command[1]))
        elif 'SET' in command:
            cache.set(command[1], command[2])
        elif 'GET' in command:
            cache.get(command[1])
        elif 'PEEK' in command:
            cache.peek(command[1])
        elif 'DUMP' in command:
            cache.dump()
