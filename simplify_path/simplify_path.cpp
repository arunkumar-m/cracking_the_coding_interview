/*
 * =====================================================================================
 *
 *       Filename:  simplify_path.cpp
 *
 *        Version:  1.0
 *        Created:  12/31/2013 12:48:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <stack>
using namespace std;

string simplifyPath(string path) {
    int len = path.length();
    string ret;
    // remove "//"
    for (int i = len - 2; i >= 0; i--) {
        if (path[i + 1] == '/' && path[i] == '/') {
            path.erase(i + 1, 1);
        }
    }
    // using stack to simulate
    string str = "";
    if (path[path.length() - 1] != '/') path.append("/");
    len = path.length();
    stack<string> dirs;
    int state = 0;
    for (int i = 0; i < len; i++) {
        if (path[i] == '/') state++;
        if (state == 1)  str += path[i];
        if (state == 2) {
            if (str == "/.." && !dirs.empty()) dirs.pop();
            if (str != "/." && str != "/..") dirs.push(str);
            state = 1;
            str = "/";
        }
    }
    if (dirs.empty()) return "/";
    ret = "";
    while (!dirs.empty()) {
        ret = dirs.top() + ret;
        dirs.pop();
    }
    return ret;
}

int main() {
    cout << simplifyPath("/home/../foo/./../a//b//c") << endl;
    return 0;
}
