/*
 * =====================================================================================
 *
 *       Filename:  scc.c
 *
 *        Version:  1.0
 *        Created:  01/05/2014 10:43:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 875714

int max(int x, int y) {
    return x > y ? x : y;
}

struct ListNode {
    int val;
    struct ListNode *next;
};

struct AdjList {
    struct ListNode *node;
};

struct ListNode *newListNode(int val) {
    struct ListNode *node = (struct ListNode *) malloc (sizeof(struct ListNode));
    node->val = val;
    return node;
}

/* global variable */
struct AdjList adj[MAX_SIZE + 1]; /* adjacency list */
struct AdjList revAdj[MAX_SIZE + 1]; /* adjacency list for the reversed graph */
int explored[MAX_SIZE + 1]; /* used when doing dfs */
int kNodes = 0; /* number of vertices */
int t; /* keep track of the time in the first pass */
int leader[MAX_SIZE + 1]; /* keep track of the leader */
int s; /* for leaders in the second pass */
int f[MAX_SIZE + 1]; /* keep track of the finishing time */
int count[MAX_SIZE + 1]; /* count */

void init() {
    s = 0;
    for (int i = 0; i <= MAX_SIZE; i++) {
        adj[i].node = NULL;
        revAdj[i].node = NULL;
        explored[i] = 0;
        count[i] = 0;
    }
}

void readData() {
    printf("Loading data ...\n");
    int v1 = 0, v2 = 0;
    while (scanf("%d %d", &v1, &v2) == 2) {
        struct ListNode *node1 = newListNode(v2);
        node1->next = adj[v1].node;
        adj[v1].node = node1;
        struct ListNode *node2 = newListNode(v1);
        node2->next = revAdj[v2].node;
        revAdj[v2].node = node2;
        kNodes = max(kNodes, v1);
    }
    printf("Data loaded!\n");
}

void dfsRev(struct AdjList *G, int i) {
    explored[i] = 1; /* mark i as explored */
    struct ListNode *head = G[i].node;
    while (head) {
        int j = head->val;
        if (explored[j] == 0) {
            dfsRev(G, j);
        }
        head = head->next;
    }
    t++;
    f[t] = i;
}

void dfsLoopRev(struct AdjList *G) {
    t = 0; /* for the finishing time in the first run */
    for (int i = kNodes; i > 0; i--) {
        if (explored[i] == 0) {
            dfsRev(G, i);
        }
    }
}

void dfs(struct AdjList *G, int i) {
    explored[i] = 1; /* mark i as explored */
    leader[i] = s; /* set leader */
    struct ListNode *head = G[i].node;
    while (head) {
        int j = head->val;
        if (explored[j] == 0) {
            dfs(G, j);
        }
        head = head->next;
    }
}

void dfsLoop(struct AdjList *G) {
    s = 0; /* for leaders in the second run */
    for (int i = kNodes; i > 0; i--) {
        int j = f[i];
        if (explored[j] == 0) {
            s = j;
            dfs(G, j);
        }
    }
}

int findMax() {
    int max_so_far = 0;
    int index = 0;
    for (int i = 1; i <= kNodes; i++) {
        if (count[i] > max_so_far) {
            max_so_far = count[i];
            index = i;
        }
    }
    count[index] = 0;
    return max_so_far;
}

void kosaraju() {
    dfsLoopRev(revAdj); /* first dfs to reversed graph G_{rev} */
    memset(explored, 0, sizeof(explored)); /* reset explored */
    dfsLoop(adj); /* second dfs to graph G */
    /* stats */
    for (int i = 1; i <= kNodes; i++) {
        count[leader[i]]++;
    }
    int kSCC = 0;
    for (int i = 1; i <= kNodes; i++) {
        if (count[i] != 0) {
            kSCC++;
        }
    }
    int a = findMax();
    int b = findMax();
    int c = findMax();
    int d = findMax();
    int e = findMax();
    printf("The number of SCCs in total: %d\n%d,%d,%d,%d,%d\n", kSCC, a, b, c, d, e);
}

int main() {
    init();
    readData();
    printf("Number of Nodes: %d\n", kNodes);
    kosaraju();
    return 0;
}
