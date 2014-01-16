/*
 * =====================================================================================
 *
 *       Filename:  labyrinth.cpp
 *
 *        Version:  1.0
 *        Created:  12/29/2013 23:18:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int i;
    int j;
    int k;
    Node(int x, int y, int z) : i(x), j(y), k(z) {}
};

int bfs(int ***labyrinth, int h, int m, int n) {
    int ***explored = new int**[h];
    int ***dist = new int**[h];
    for (int i = 0; i < h; i++) {
        explored[i] = new int*[m];
        dist[i] = new int*[m];
        for (int j = 0; j < m; j++) {
            explored[i][j] = new int[n];
            dist[i][j] = new int[n];
            for (int k = 0; k < n; k++) {
                explored[i][j][k] = 0;
                dist[i][j][k] = INT_MAX;
            }
        }
    }

    queue<Node *> q;
    q.push(new Node(0, 0, 0));
    dist[0][0][0] = 0;

    while (!q.empty()) {
        Node *curr = q.front();
        cout << curr->i << " " << curr->j << " " << curr->k << endl;
        q.pop();
        if (explored[curr->i][curr->j][curr->k] == 1) {
            continue;
        }
        if (labyrinth[curr->i][curr->j][curr->k] == 2) {
            return dist[curr->i][curr->j][curr->k];
        }
        explored[curr->i][curr->j][curr->k] = 1;
        // up
        if (curr->j - 1 >= 0 && explored[curr->i][curr->j - 1][curr->k] == 0 && labyrinth[curr->i][curr->j - 1][curr->k] != 1) {
            dist[curr->i][curr->j - 1][curr->k] = dist[curr->i][curr->j][curr->k] + 1;
            q.push(new Node(curr->i, curr->j - 1, curr->k));
        }
        // left
        if (curr->k - 1 >= 0 && explored[curr->i][curr->j][curr->k - 1] == 0 && labyrinth[curr->i][curr->j][curr->k - 1] != 1) {
            dist[curr->i][curr->j][curr->k - 1] = dist[curr->i][curr->j][curr->k] + 1;
            q.push(new Node(curr->i, curr->j, curr->k - 1));
        }
        // right
        if (curr->k + 1 < n && explored[curr->i][curr->j][curr->k + 1] == 0 && labyrinth[curr->i][curr->j][curr->k + 1] != 1) {
            dist[curr->i][curr->j][curr->k + 1] = dist[curr->i][curr->j][curr->k] + 1;
            q.push(new Node(curr->i, curr->j, curr->k + 1));
        }
        // down
        if (curr->j + 1 < m && explored[curr->i][curr->j + 1][curr->k] == 0 && labyrinth[curr->i][curr->j + 1][curr->k] != 1) {
            dist[curr->i][curr->j + 1][curr->k] = dist[curr->i][curr->j][curr->k] + 1;
            q.push(new Node(curr->i, curr->j + 1, curr->k));
        }
        // downstair
        if (curr->i + 1 < h && explored[curr->i + 1][curr->j][curr->k] == 0 && labyrinth[curr->i + 1][curr->j][curr->k] != 1) {
            dist[curr->i + 1][curr->j][curr->k] = dist[curr->i][curr->j][curr->k] + 1;
            q.push(new Node(curr->i + 1, curr->j, curr->k));
        }
    }
    return INT_MAX;
}

int main() {
    int ***labyrinth;
    labyrinth = new int **[3];
    for (int i = 0; i < 3; i++) {
        labyrinth[i] = new int*[3];
        for (int j = 0; j < 3; j++) {
            labyrinth[i][j] = new int[3];
        }
    }

    labyrinth[0][0][0] = 0;
    labyrinth[0][0][1] = 0;
    labyrinth[0][0][2] = 0;
    labyrinth[0][1][0] = 1;
    labyrinth[0][1][1] = 1;
    labyrinth[0][1][2] = 0;
    labyrinth[0][2][0] = 0;
    labyrinth[0][2][1] = 0;
    labyrinth[0][2][2] = 0;

    labyrinth[1][0][0] = 1;
    labyrinth[1][0][1] = 1;
    labyrinth[1][0][2] = 1;
    labyrinth[1][1][0] = 0;
    labyrinth[1][1][1] = 0;
    labyrinth[1][1][2] = 1;
    labyrinth[1][2][0] = 0;
    labyrinth[1][2][1] = 1;
    labyrinth[1][2][2] = 1;

    labyrinth[2][0][0] = 1;
    labyrinth[2][0][1] = 1;
    labyrinth[2][0][2] = 1;
    labyrinth[2][1][0] = 1;
    labyrinth[2][1][1] = 0;
    labyrinth[2][1][2] = 0;
    labyrinth[2][2][0] = 1;
    labyrinth[2][2][1] = 0;
    labyrinth[2][2][2] = 2;

    cout << bfs(labyrinth, 3, 3, 3) << endl;

    return 0;
}
