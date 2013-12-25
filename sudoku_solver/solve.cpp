/*
 * =====================================================================================
 *
 *       Filename:  solve.cpp
 *
 *        Version:  1.0
 *        Created:  12/24/2013 11:24:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

const string digits[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
const string row[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
const string col[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

set<string> squares;
set<vector<string> > unitlist;
map<string, vector<vector<string> > > units;
map<string, vector<string> > peers;
map<string, vector<string> > grid;

void printVecStr(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ",";
    }
}


void printBoard(vector<vector<char> > &board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void printGrid(map<string, vector<string> > &grid) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            string pos = row[i] + col[j];
            printVecStr(grid[pos]);
            cout << " | ";
        }
        cout << endl;
    }
}

void init() {
    // squares
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            squares.insert(row[i] + col[j]);
        }
    }
    // row
    for (int i = 0; i < 9; i++) {
        vector<string> vec;
        for (int j = 0; j < 9; j++) {
            vec.push_back(row[i] + col[j]);
        }
        unitlist.insert(vec);
    }
    // column
    for (int i = 0; i < 9; i++) {
        vector<string> vec;
        for (int j = 0; j < 9; j++) {
            vec.push_back(row[j] + col[i]);
        }
        unitlist.insert(vec);
    }
    // unitlist
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            vector<string> vec;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    vec.push_back(row[i + k] + col[j + l]);
                }
            }
            unitlist.insert(vec);
        }
    }
    // units
    set<vector<string> >::iterator it;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            vector<vector<string> > vec;
            string pos = row[i] + col[j];
            for (it = unitlist.begin(); it != unitlist.end(); it++) {
                if (find((*it).begin(), (*it).end(), pos) != (*it).end()) {
                    vec.push_back(*it);
                }
            }
            units[pos] = vec;
        }
    }
    // peers
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            string pos = row[i] + col[j];
            set<string> s;
            vector<string> v;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < units[pos][k].size(); l++) {
                    s.insert(units[pos][k][l]);
                }
            }
            s.erase(s.find(pos));
            v.assign(s.begin(), s.end());
            peers[pos] = v;
        }
    }
}

bool assign(map<string, vector<string> > &grid, string pos, string value) {
    vector<string> v;
    v.push_back(value);
    grid[pos] = v;
    for (int k = 0; k < peers[pos].size(); k++) {
        vector<string>::iterator it = find(grid[peers[pos][k]].begin(), grid[peers[pos][k]].end(), value);
        if (it != grid[peers[pos][k]].end()) {
            grid[peers[pos][k]].erase(it);
            if (grid[peers[pos][k]].size() == 0) return false;
            if (grid[peers[pos][k]].size() == 1) {
                if (!assign(grid, peers[pos][k], grid[peers[pos][k]][0])) return false;
            }
        }
    }
    return true;
}

void initGrid(vector<vector<char> > &board) {
    // grid
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            string pos = row[i] + col[j];
            vector<string> v;
            for (int k = 0; k < 9; k++) {
                v.push_back(digits[k]);
            }
            grid[pos] = v;
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            string pos = row[i] + col[j];
            if (board[i][j] != '.') {
                assign(grid, pos, string(1, board[i][j]));
            }
        }
    }
}

bool search(map<string, vector<string> > &grid) {
    int min_so_far = 9;
    string next = "";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            string pos = row[i] + col[j];
            int size = grid[pos].size();
            if (size >= 2 && size < min_so_far) {
                min_so_far = size;
                next = pos;
            }
        }
    }

    if (next == "") {
        return true;
    }

    for (int i = 0; i < grid[next].size(); i++) {
        map<string, vector<string> > grid_copy = grid;
        if (assign(grid_copy, next, grid[next][i])) {
            if (search(grid_copy)) {
                grid = grid_copy;
                return true;
            }
        }
    }

    return false;
}

void convertGridToBoard(vector<vector<char> > &board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            string pos = row[i] + col[j];
            board[i][j] = grid[pos][0][0];
        }
    }
}

void solveSudoku(vector<vector<char> > &board) {
    init();
    initGrid(board);
    search(grid);
    convertGridToBoard(board);
    printBoard(board);
}

int main() {
    vector<vector<char> > board(9, vector<char>(9));
    // easy
    char arr[] = "003020600900305001001806400008102900700000008006708200002609500800203009005010300"; // 0.018 seconds
    // char arr[] = "200080300060070084030500209000105408000000000402706000301007040720040060004010003";
    // hard
    // char arr[] = "4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......";
    // char arr[] = "52...6.........7.13...........4..8..6......5...........418.........3..2...87.....";
    // char arr[] = "6.....8.3.4.7.................5.4.7.3..2.....1.6.......2.....5.....8.6......1....";
    // char arr[] = "48.3............71.2.......7.5....6....2..8.............1.76...3.....4......5...."; // 9.947 seconds!
    // char arr[] = "....14....3....2...7..........9...3.6.1.............8.2.....1.4....5.6.....7.8..."; // 2.415 seconds
    // char arr[] = "......52..8.4......3...9...5.1...6..2..7........3.....6...1..........7.4.......3."; // 24.935 seconds, Wow!
    for (int i = 0; i < 9; i++) {
        board[i].assign(arr + 9 * i, arr + 9 * i + 9);
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '0') {
                board[i][j] = '.';
            }
        }
    }
    solveSudoku(board);
    return 0;
}
