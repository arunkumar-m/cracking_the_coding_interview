/*
 * =====================================================================================
 *
 *       Filename:  brute_force.cpp
 *
 *        Version:  1.0
 *        Created:  12/20/2013 20:36:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool dfs(vector<vector<char> > &board, int i, int j, int curr, string word, vector<vector<int> > &explored) {
    int m = board.size();
    int n = board[0].size();
    if (curr == word.length()) return true;
    if (explored[i][j] || board[i][j] != word[curr]) return false;
    if (curr + 1 == word.length()) return true;
    // mark
    explored[i][j] = 1;
    // cout << curr << " " << i << " " << j << ": " << board[i][j] << " " << word[curr] << endl;
    if (i + 1 < m && dfs(board, i + 1, j, curr + 1, word, explored)) {
        return true;
    }
    if (i - 1 >= 0 && dfs(board, i - 1, j, curr + 1, word, explored)) {
        return true;
    }
    if (j + 1 < n && dfs(board, i, j + 1, curr + 1, word, explored)) {
        return true;
    }
    if (j - 1 >= 0 && dfs(board, i, j - 1, curr + 1, word, explored)) {
        return true;
    }
    // unmark
    explored[i][j] = 0;
    return false;
}

bool exist(vector<vector<char> > &board, string word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<int> > explored(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        explored[i].assign(n, 0);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(board, i, j, 0, word, explored)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char arr[][4] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    vector<vector<char> > board(3, vector<char>(4));
    for (int i = 0; i < 3; i++) {
        board[i].assign(arr[i], arr[i] + 4);
    }
    cout << exist(board, "SEE") << endl;
    cout << exist(board, "ABCCED") << endl;
    cout << exist(board, "ABCB") << endl;
    return 0;
}
