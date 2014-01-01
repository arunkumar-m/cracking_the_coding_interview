/*
 * =====================================================================================
 *
 *       Filename:  solve.cpp
 *
 *        Version:  1.0
 *        Created:  01/01/2014 01:06:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void printPairs(vector<pair<int, int> > pairs) {
    for (int i = 0; i < pairs.size(); i++) {
        cout << "(" << pairs[i].first << "," << pairs[i].second << "), ";
    }
    cout << endl;
}

void printBoard(vector<vector<char> > &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

vector<pair<int, int> > visit(vector<vector<char> > &board, int i, int j, vector<vector<bool> > &explored) {
    int flag = 1;
    int m = board.size();
    int n = m == 0 ? 0 : board[0].size();
    vector<pair<int, int> > pairs;
    stack<pair<int, int> > s;
    s.push(make_pair(i, j));
    while (!s.empty()) {
        int x = s.top().first, y = s.top().second;
        s.pop();
        if (x >= m || x < 0 || y < 0 || y >= n) {
            flag = 0;
            continue;
        }
        if (explored[x][y] == true) continue;
        pairs.push_back(make_pair(x, y));
        explored[x][y] = true;
        s.push(make_pair(x + 1, y));
        s.push(make_pair(x - 1, y));
        s.push(make_pair(x, y + 1));
        s.push(make_pair(x, y - 1));
    }
    return flag ? pairs : vector<pair<int, int> >(0);
}

void dfs(vector<vector<char> > &board) {
    int m = board.size();
    int n = m == 0 ? 0 : board[0].size();
    vector<vector<bool> > explored(m, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'X') {
                explored[i][j] = true;
            }
            else {
                explored[i][j] = false;
            }
        }
    }
    vector<pair<int, int> > pairs;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (explored[i][j] == false) {
                vector<pair<int, int> > res = visit(board, i, j, explored);
                pairs.insert(pairs.end(), res.begin(), res.end());
            }
        }
    }
    // printPairs(pairs);
    for (int i = 0; i < pairs.size(); i++) {
        int x = pairs[i].first, y = pairs[i].second;
        board[x][y] = 'X';
    }
}

void solve(vector<vector<char> > &board) {
    dfs(board);
    // printBoard(board);
}

int main() {
    vector<vector<char> > board(4, vector<char>(4));
    char arr[4][4] = {
        {'X','X','X','O'},
        {'X','O','O','X'},
        {'X','O','O','X'},
        {'X','X','X','O'},
    };
    for (int i = 0; i < 4; i++) {
        board[i].assign(arr[i], arr[i] + 4);
    }
    solve(board);
    return 0;
}
