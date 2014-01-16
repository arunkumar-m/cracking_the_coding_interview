# Median Maintenance Problem
# Implement the algorithm using heap

from heapq import * # all basic operations about heap

print "Loading data ..."
data = open('Median.txt', 'r').readlines()
data = map(int, data)
# data = [1,2,3,4,5,6,7,8,9,10] # small test case
print "Data loaded!"

print "The size of the data:", len(data)

minh = [] # min heap
maxh = [(-data[0], data[0])] # max heap

median = [data[0]]

for d in data[1:]:
    y = maxh[0][1]
    if d < y: # the element is smaller than the smallest element in the max heap
        heappush(maxh, (-d, d))
    else:
        heappush(minh, (d, d))

    if len(minh) > len(maxh):
        x = heappop(minh)[1]
        heappush(maxh, (-x, x))
    elif len(maxh) > len(minh) + 1: # invariant: len(minh) <= len(maxh) <= len(minh) + 1
        x = heappop(maxh)[1]
        heappush(minh, (x, x))

    if len(minh) == len(maxh):
        median.append(maxh[0][1])
    else:
        median.append(maxh[0][1])

# result
print sum(median) % 10000
