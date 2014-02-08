import doctest
import sys

args = sys.argv[1:]
# print args

def rpn2infix(args):
    """ test rpn2infix
    >>> rpn2infix("1 _".split())
    '_1'
    >>> rpn2infix("3 4 _ + 5 * 6 -".split())
    '(3 + _4) * 5 - 6'
    >>> rpn2infix("3 _ 4 + 5 6 - *".split())
    '(_3 + 4) * (5 - 6)'
    >>> rpn2infix("2 3 + *".split())
    error parsing input ['2', '3', '+', '*']
    """
    priority = {}
    priority["-"] = 1
    priority["+"] = 1
    priority["*"] = 2
    priority["/"] = 2
    priority["_"] = 3
    stack = []
    if len(args) == 0: return
    for arg in args:
        ret = ""
        if arg in "_+-*/": # operater
            try:
                if arg == "_":
                    num1, prio1 = stack.pop()
                    stack.append(("_" + num1, priority["_"]))
                else:
                    num2, prio2 = stack.pop()
                    num1, prio1 = stack.pop()
                    if prio1 < priority[arg]:
                        num1 = "(" + num1 + ")"
                    if prio2 < priority[arg]:
                        num2 = "(" + num2 + ")"
                    ret += " " + num1 + " " + arg + " " + num2
                    stack.append((ret.strip(), priority[arg]))
            except:
                print "error parsing input", args
                return
        else: # number
            stack.append((arg, 4))
    if len(stack) == 1:
        return stack[0][0]
    else:
        print "error parsing input", args

if __name__ == '__main__':
    rpn2infix("3 4 _ + 5 * 6 -".split())
