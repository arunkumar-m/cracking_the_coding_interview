/*
 * =====================================================================================
 *
 *       Filename:  jugs.cpp
 *
 *        Version:  1.0
 *        Created:  01/17/2014 21:46:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1010;
const char operation[6][10] = {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A"};

enum actionType {
    fillA, // 0
    fillB, // 1
    emptyA, // 2
    emptyB, // 3
    pourAB, // 4
    pourBA, // 5
};

// memorize the state we have reached
struct State {
    int ca, cb;
    int action;
    State *prev;
    State() { prev = NULL; }
    State(int x, int y, int z) : ca(x), cb(y), action(z), prev(NULL) {}
} states[MAX][MAX];

bool visited[MAX][MAX];

void output(State s) {
    if (s.prev == NULL) {
        return;
    }
    output(*s.prev);
    cout << operation[s.action] << endl;
}

void bfs(int ca, int cb, int n) {
    queue<State> q;
    q.push(State(0, 0, -1));
    while (!q.empty()) {
        State curr = q.front();
        q.pop();
        visited[curr.ca][curr.cb] = true;
        if (curr.cb == n) {
            // success
            output(states[curr.ca][curr.cb]);
            cout << "success" << endl;
            return;
        }
        // fill A
        if (!visited[ca][curr.cb]) {
            visited[ca][curr.cb] = true;
            states[ca][curr.cb].action = fillA;
            states[ca][curr.cb].prev = &states[curr.ca][curr.cb];
            q.push(State(ca, curr.cb, fillA));
        }
        // fill B
        if (!visited[curr.ca][cb]) {
            visited[curr.ca][cb] = true;
            states[curr.ca][cb].action = fillB;
            states[curr.ca][cb].prev = &states[curr.ca][curr.cb];
            q.push(State(curr.ca, cb, fillB));
        }
        // empty A
        if (!visited[0][curr.cb]) {
            visited[0][curr.cb] = true;
            states[0][curr.cb].action = emptyA;
            states[0][curr.cb].prev = &states[curr.ca][curr.cb];
            q.push(State(0, curr.cb, emptyA));
        }
        // empty B
        if (!visited[curr.ca][0]) {
            visited[curr.ca][0] = true;
            states[curr.ca][0].action = emptyB;
            states[curr.ca][0].prev = &states[curr.ca][curr.cb];
            q.push(State(curr.ca, 0, emptyB));
        }
        // pour A B
        int water = min(curr.ca, cb - curr.cb);
        if (!visited[curr.ca - water][curr.cb + water]) {
            visited[curr.ca - water][curr.cb + water] = true;
            states[curr.ca - water][curr.cb + water].action = pourAB;
            states[curr.ca - water][curr.cb + water].prev= &states[curr.ca][curr.cb];
            q.push(State(curr.ca - water, curr.cb + water, pourAB));
        }
        // pour B A
        water = min(curr.cb, ca - curr.ca);
        if (!visited[curr.ca + water][curr.cb - water]) {
            visited[curr.ca + water][curr.cb - water] = true;
            states[curr.ca + water][curr.cb - water].action = pourBA;
            states[curr.ca + water][curr.cb - water].prev= &states[curr.ca][curr.cb];
            q.push(State(curr.ca + water, curr.cb - water, pourBA));
        }
    }
}

int main() {
    int Ca, Cb, N; // Ca and Cb are the capacities of the jugs A and B, and N is the goal.
    while (cin >> Ca >> Cb >> N) {
        memset(visited, false, sizeof(visited));
        bfs(Ca, Cb, N);
    }
    return 0;
}
