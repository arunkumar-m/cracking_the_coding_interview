/*
 * =====================================================================================
 *
 *       Filename:  longest_valid_parentheses.cpp
 *
 *        Version:  1.0
 *        Created:  12/23/2013 23:23:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    int maxLen = 0;
    int last = 0; // the index after last invalid sequence
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        }
        else {
            if (!st.empty()) {
                st.pop();
                if (st.empty()) {
                    maxLen = max(maxLen, i - last + 1);
                }
                else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
            else {
                last = i + 1;
            }
        }
    }
    return maxLen;
}

int main() {
    cout << longestValidParentheses("()(())") << endl;
    cout << longestValidParentheses(")()())") << endl;
    return 0;
}
