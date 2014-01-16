/*
 * =====================================================================================
 *
 *       Filename:  edit_distance.cpp
 *
 *        Version:  1.0
 *        Created:  12/20/2013 17:57:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

void print2DArray(int **table, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    // init table
    int **table = new int*[m+1];
    for (int i = 0; i <= m; i++) {
        table[i] = new int[n+1];
        for (int j = 0; j <= n; j++) {
            table[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        table[i][0] = i;
    }
    for (int i = 1; i <= n; i++) {
        table[0][i] = i;
    }
    // fill out the table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            table[i][j] = min(table[i-1][j-1]+(word1[i-1]!=word2[j-1]), min(table[i-1][j]+1, table[i][j-1]+1));
        }
    }
    // print2DArray(table, m+1, n+1);
    return table[m][n];
}

int main() {
    cout << minDistance("INTENTION", "EXECUTION") << endl;
    return 0;
}
