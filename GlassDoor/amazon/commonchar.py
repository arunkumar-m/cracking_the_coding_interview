def commonchar(a, b):
    s1 = set([])
    s2 = set([])
    for i in range(len(a)):
        s1.add(a[i])
    for i in range(len(b)):
        s2.add(b[i])
    return s1.intersection(s2)

print commonchar("hello", "elbow")
