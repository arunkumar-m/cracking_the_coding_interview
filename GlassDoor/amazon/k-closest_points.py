"""
given an int k and a list of 2-D (x,y) points, write a piece of code that
will return the K closest points to the origin (which is the point(0,0))
"""

def kclosestpoints(points, k):
    """Return k closest points to the origin

    >>> kclosestpoints([(1,1), (0,0), (2,2), (1,2), (3,2)], 2)
    [((0, 0), 0), ((1, 1), 2)]
    
    """
    dist = {p : 0 for p in points}
    for point in points:
        dist[point] = point[0] ** 2 + point[1] ** 2
    dist = sorted(dist.items(), key=lambda x : x[1], reverse=False)
    return dist[:k]

if __name__ == '__main__':
    import doctest
    doctest.testmod()
