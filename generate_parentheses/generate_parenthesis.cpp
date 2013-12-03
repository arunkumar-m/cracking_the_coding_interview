/*
 * =====================================================================================
 *
 *       Filename:  generate_parenthesis.cpp
 *
 *        Version:  1.0
 *        Created:  12/02/2013 21:58:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generate(vector<string> &result, string s, int n, int l, int r) {
    if (l == n) {
        result.push_back(s.append(n - r, ')'));
        return;
    }
    generate(result, s + '(', n, l + 1, r);
    if (l > r) {
        generate(result, s + ')', n, l, r + 1);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    if (n == 0)
        return result;
    generate(result, "", n, 0, 0);
    return result;
}

void printV(vector<string> str) {
    int i = 0;
    for (i = 0; i < str.size(); i++) {
        cout << str[i] << endl;
    }
}

int main() {
    vector<string> str = generateParenthesis(3);
    printV(str);
    return 0;
}
