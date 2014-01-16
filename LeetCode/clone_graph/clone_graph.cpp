/*
 * =====================================================================================
 *
 *       Filename:  clone_graph.cpp
 *
 *        Version:  1.0
 *        Created:  12/23/2013 15:39:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

UndirectedGraphNode *clone(UndirectedGraphNode *node) {
    if (!node) return NULL;
    queue<UndirectedGraphNode *> q;
    map<UndirectedGraphNode *, UndirectedGraphNode *> m;
    UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
    m[node] = copy;
    q.push(node);
    while (!q.empty()) {
        UndirectedGraphNode *curr = q.front();
        q.pop();
        for (int i = 0; i < curr->neighbors.size(); i++) {
            if (m.find(curr->neighbors[i]) == m.end()) {
                UndirectedGraphNode *neighbor = new UndirectedGraphNode(curr->neighbors[i]->label);
                m[curr->neighbors[i]] = neighbor;
                q.push(curr->neighbors[i]);
            }
            m[curr]->neighbors.push_back(m[curr->neighbors[i]]);
        }
    }
    return copy;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    map<int, UndirectedGraphNode *> m;
    return clone(node);
}

void printGraph(UndirectedGraphNode *node, set<UndirectedGraphNode *> s) {
    if (s.find(node) != s.end()) {
        return;
    }
    s.insert(node);
    cout << "#" << node->label;
    for (int i = 0; i < node->neighbors.size(); i++) {
        cout << "," << node->neighbors[i]->label;
    }
    for (int i = 0; i < node->neighbors.size(); i++) {
        printGraph(node->neighbors[i], s);
    }
}

int main() {
    UndirectedGraphNode *node0 = new UndirectedGraphNode(0);
    UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode *node2 = new UndirectedGraphNode(2);
    node0->neighbors.push_back(node1);
    node0->neighbors.push_back(node2);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node2);
    UndirectedGraphNode *node = cloneGraph(node0);
    set<UndirectedGraphNode *> visited;
    printGraph(node0, visited);
    return 0;
}
