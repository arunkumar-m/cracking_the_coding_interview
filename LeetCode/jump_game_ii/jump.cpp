/*
 * =====================================================================================
 *
 *       Filename:  jump.cpp
 *
 *        Version:  1.0
 *        Created:  12/23/2013 19:48:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
using namespace std;

// Time limit exceeded
int jump_dp(int A[], int n) {
    // init
    int *D = new int[n];
    D[0] = 0;
    for (int i = 1; i < n; i++) {
        D[i] = INT_MAX;
    }
    // fill in the table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] + j >= i) {
                D[i] = min(D[i], D[j] + 1);
            }
        }
    }
    return D[n - 1];
}

// shortest path
int bfs(int A[], int n) {
    int *explored = new int[n];
    int *dist = new int[n];
    for (int i = 0; i < n; i++) {
        explored[i] = 0;
        dist[i] = INT_MAX;
    }
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    explored[0] = 1;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int j = i + 1; j < n && j <= A[i] + i; j++) {
            if (explored[j] == 0) {
                dist[j] = dist[i] + 1;
                q.push(j);
                explored[j] = 1;
            }
        }
    }
    delete[] explored;
    delete[] dist;
    return dist[n - 1];
}

int jump(int A[], int n) {
    int min_step = 0;
    int max_dist = 0; // distance we can get to within min_step + 1
    int dist = 0; // distance we can reach within min_step
    for (int i = 0; i < n; i++) {
        if (i > dist) {
            dist = max_dist;
            ++min_step;
        }
        max_dist =max(max_dist,  A[i] + i);
    }
    return min_step;
}

int main() {
    int A[] = {3,1,0,0,4};
    cout << jump(A, 5) << endl;
    return 0;
}
