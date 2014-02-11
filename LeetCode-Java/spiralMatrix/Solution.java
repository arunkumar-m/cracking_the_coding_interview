import java.util.*;

public class Solution {

    public static void spiral(int[][] matrix, int x, int y, int h, int w, ArrayList<Integer> ret) {
        if (h <= 0 || w <= 0) return;
        // base case
        if (h == 1) {
            for (int i = y; i < y + w; i++) {
                ret.add(matrix[x][i]);
            }
            return;
        }
        if (w == 1) {
            for (int i = x; i < x + h; i++) {
                ret.add(matrix[i][y]);
            }
            return;
        }
        // go right
        for (int i = y; i < y + w; i++) {
            ret.add(matrix[x][i]);
        }
        // go down
        for (int i = x + 1; i < x + h; i++) {
            ret.add(matrix[i][y + w - 1]);
        }
        // go left
        for (int i = y + w - 2; i >= y; i--) {
            ret.add(matrix[x + h - 1][i]);
        }
        // go up
        for (int i = x + h - 2; i > x; i--) {
            ret.add(matrix[i][y]);
        }

        // recurse
        spiral(matrix, x + 1, y + 1, h - 2, w - 2, ret);
    }

    public static ArrayList<Integer> spiralOrder(int[][] matrix) {
        int h = matrix.length;
        int w = h > 0 ? matrix[0].length : 0;
        ArrayList<Integer> ret = new ArrayList<Integer>();
        spiral(matrix, 0, 0, h, w, ret);
        return ret;
    }

    public static void main(String[] argv) {
        int[][] matrix = new int[3][3];
        matrix[0][0] = 1;
        matrix[0][1] = 2;
        matrix[0][2] = 3;
        matrix[1][0] = 4;
        matrix[1][1] = 5;
        matrix[1][2] = 6;
        matrix[2][0] = 7;
        matrix[2][1] = 8;
        matrix[2][2] = 9;
        ArrayList<Integer> ret = spiralOrder(matrix);
        for (int i : ret) {
            System.out.print(i);
            System.out.print(" ");
        }
    }
}
