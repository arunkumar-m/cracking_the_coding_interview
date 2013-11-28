/*
 * =====================================================================================
 *
 *       Filename:  word_ladder.cpp
 *
 *        Version:  1.0
 *        Created:  11/28/2013 08:37:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <set>
#include <map>
#include <queue>
using namespace std;

int ladderLength(string start, string end, set<string> &dict) {
    int len = 0;
    if (start == end)
        return len;

    set<string> visited;
    map<string, unsigned int> dist;
    queue<string> q;

    dict.erase(end);
    for (set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
        dist[*it] = 0xFFFFFFFF;
    }

    dist[start] = 0;
    dist[end] = 0xFFFFFFFF;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        string s = q.front();
        q.pop();

        // do not compare each leeter of the word with the words in dict whose time complexity is O(m * n) where m is the length of the word and n is the number of words in dict
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < 26; j++) {
                string t = s;
                t[i] = 'a' + j;
                if (t == end) {
                    dist[end] = min(dist[end], dist[s] + 2);
                    // cout << "update: " << t << " " << dist[end] << endl;
                }
                if (dict.find(t) != dict.end() && visited.find(t) == visited.end()) {
                    q.push(t);
                    visited.insert(t);
                    dist[t] = min(dist[t], dist[s] + 1);
                    // cout << t << " " << dist[t] << endl;
                }
            }
        }
    }

    return dist[end] == 0xFFFFFFFF ? 0 : dist[end];
}

int main() {
    set<string> dict;
//    dict.insert("hot");
//    dict.insert("dot");
//    dict.insert("dog");
//    dict.insert("lot");
//    dict.insert("log");
//    cout << ladderLength("hit", "cog", dict) << endl;
    dict.insert("a");
    dict.insert("c");
    dict.insert("b");
    cout << ladderLength("a", "c", dict) << endl;
    return 0;
}
