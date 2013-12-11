#include <iostream>
#include <vector>
using namespace std;

bool isValidRow(vector<vector<char> > &board, int row) {
    int cnt[10] = {0};
    for (int i = 0; i < board[row].size(); i++) {
        if (board[row][i] == '.') {
            continue;
        }
        else {
            cnt[board[row][i] - '0']++;
            if (cnt[board[row][i] - '0'] > 1) {
                return false;
            }
        }
    }
    return true;
}

bool isValidColumn(vector<vector<char> > &board, int col) {
    int cnt[10] = {0};
    for (int i = 0; i < board.size(); i++) {
        if (board[i][col] == '.') {
            continue;
        }
        else {
            cnt[board[i][col] - '0']++;
            if (cnt[board[i][col] - '0'] > 1) {
                return false;
            }
        }
    }
    return true;
}

bool isValidRegion(vector<vector<char> > &board, int row, int col) {
    int cnt[10] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[row + i][col + j] == '.') {
                continue;
            }
            else {
                cnt[board[row + i][col + j] - '0']++;
                if (cnt[board[row + i][col + j] - '0'] > 1) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char> > &board) {
    /* check row and column */
    for (int i = 0; i < board.size(); i++) {
        if (isValidRow(board, i) && isValidColumn(board, i)) {
            continue;
        }
        else {
            return false;
        }
    }

    /* check region */
    for (int i = 0; i < board.size(); i += 3) {
        for (int j = 0; j < board.size(); j += 3) {
            if (isValidRegion(board, i, j)) {
                continue;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char> > board(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = '.';
        }
    }
    board[0][0] = '1';
    board[1][1] = '1';
    cout << isValidSudoku(board) << endl;
    return 0;
}
