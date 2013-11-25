# Max Points on a Line

Given _n_ points on a 2D plane, find the maximum number of points that
lie on the same straight line.

## Straightforward Solution

Note that a line can be represented as _ax + by + c_. For every pairs of
points, the code calculates _a_, _b_, _c_. Then, the code counts how
many points are in the line.

Not a very efficient algorithm though, it passes the test of LeetCode.

## Better Solution

Fix one point, find the maximum number of other points that have the
same polar angle.

To be implemented.
