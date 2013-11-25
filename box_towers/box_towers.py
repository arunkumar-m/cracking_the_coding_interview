import copy

def get_wl(box, h):
    flag = 0
    wl = []
    for dim in box:
        if dim != h:
            wl.append(dim)
        elif dim == h and flag:
            wl.append(dim)
        else:
            flag = 1
    return wl

def is_valid(tower, width, length):
    if len(tower) < 1:
        return True
    else:
        top = tower[-1]
        if (top[0] < width or top[1] < length) and (top[0] < length or top[1] < width):
            return False
        else:
            return True

def search(boxes, tower, height, max_height=0):
    for i in xrange(len(boxes)):
        box = boxes[i]
        new_boxes = copy.deepcopy(boxes)
        del new_boxes[i]
        for h in box:
            new_tower = copy.deepcopy(tower)
            width, length = get_wl(box, h)
            if is_valid(tower, width, length):
                new_tower.append(box)
                max_height = max(max_height, search(new_boxes, new_tower, height + h, height + h))
            else:
                max_height = max(max_height, height)
    return max_height


def main():
    n = int(raw_input())

    boxes = []
    for i in xrange(n):
        data = sorted([int(i) for i in raw_input().strip().split()])
        boxes.append([data[0], data[1], data[2]])

    print search(boxes, [], 0)

def test():
    f = open('input_01.txt', 'r')
    n = int(f.readline().strip())
    boxes = []
    for line in f:
        data = sorted([int(i) for i in line.strip().split()])
        boxes.append([data[0], data[1], data[2]])
    f.close()

    print boxes

    print search(boxes, [], 0)

if __name__ == '__main__':
    main()
    #test()
