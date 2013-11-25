# Box Towers

In the not so distant future, Box has commissioned you to design the new Box Worldwide Headquarters - The Box Towers. The design principal is a series of boxes (what else?),  one on top of each other. Each department in Box will be located in a different box.

Now each department has decided they have different needs in terms of the height, width and length (depth) of their box. For structural integrity reasons, you must also not place a box that has a larger footprint on top of a box with a smaller footprint i.e a box can be kept on the top of another box only if the Length of the upper box is not more than the Length of box below and the same for Width. You may rotate the boxes as necessary to make any of the face as base i.e 3D rotation is allowed.

Given the set of boxes, come up with the tallest building possible while satisfying the above constraints. It may not be possible to use all the boxes.

## Input Format:

1st line contains the number of boxes , N.

Then follow N lines describing the configuration of each of the N boxes. Each of these lines contain three integers (length, width and height of the box)

## Output Format:

Output a single line which is the height of the tallest possible building that can be formed with some of the boxes given and satisfying the constraints.

## Sample Input

    3
    5 2 4
    1 4 2
    4 4 2

 

## Sample Output

    13

## Explanation

Place box 2 on top below which is box 1 and the bottom-most box is box 3. Box 2 is placed with base ( 1 2 ) and height 4 , box 1 is placed with base ( 2 4 ) and height 5, and box 3 is placed with base ( 2 4 ) and height 4. So total height of this tower is 13.

## Constraints

N, the number of boxes is not more than 20

For any box , 1 <= Length,Width,Height <= 100

## Solution

Simple exhaustive search. Try every possibilibities.

Don't know what's wrong. Needs more testing.

Only passed one test. Five tests failed. Four tests exceeded time limit.
