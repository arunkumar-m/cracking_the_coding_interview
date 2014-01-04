# Valid Number

Validate if a given string is numeric.

Some examples:

"0" => true

" 0.1 " => true

"abc" => false

"1 a" => false

"2e10" => true

**Note:** It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

## Solution

The solution is a very elegant one and I learn a lot from it, so I just copy it from [the LeetCode post](http://discuss.leetcode.com/questions/241/valid-number).

It utilizes finite state machine to solve this problem and it is very
simple and logical.

Interestingly, there is a programming style called [automata-based
programming](http://en.wikipedia.org/wiki/Automata-based_programming).
