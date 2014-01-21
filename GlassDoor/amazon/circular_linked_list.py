"""
Reference: http://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
"""

class node:
    def __init__(self, v):
        self.next = None
        self.value = v
    def __repr__(self):
        return "(NODE " + str(self.value) + ")"

n1 = node(1)
n2 = node(2)
n3 = node(3)
n4 = node(4)
n5 = node(5)

n1.next = n2
n2.next = n3
n3.next = n4
n4.next = n2

def hasCircle(head):
    turtle = head
    hare = head
    while 1:
        turtle = turtle.next
        if hare.next is None:
            return False
        hare = hare.next
        if hare.next.next is None:
            return False
        hare = hare.next
        if turtle == hare:
            break
    mu = 0
    turtle = head
    while turtle != hare:
        turtle = turtle.next
        hare = hare.next
        mu += 1
    print "pos:", mu

    lam = 1
    hare = turtle.next
    while turtle != hare:
        hare = hare.next
        lam += 1
    print "lam:", lam
    return True

print hasCircle(n1)
