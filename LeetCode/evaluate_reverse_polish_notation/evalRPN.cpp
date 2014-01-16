/*
 * =====================================================================================
 *
 *       Filename:  evalRPN.cpp
 *
 *        Version:  1.0
 *        Created:  11/27/2013 23:22:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int evalRPN(vector<string> &tokens) {
    if (tokens.size() == 0)
        return 0;
    int i = 0, num1, num2;
    stack<int> st;
    st.push(atoi(tokens[i].c_str()));
    for (; i < tokens.size(); i++) {
        if (tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "-" || tokens[i] == "/") {
            num2 = st.top();
            st.pop();
            num1 = st.top();
            st.pop();
            if (tokens[i] == "+")
                st.push(num1 + num2);
            else if (tokens[i] == "-")
                st.push(num1 - num2);
            else if (tokens[i] == "/")
                st.push(num1 / num2);
            else
                st.push(num1 * num2);
        }
        else {
            st.push(atoi(tokens[i].c_str()));
        }
    }
    return st.top();
}

int main() {
    vector<string> tokens;
//    tokens.push_back("2");
//    tokens.push_back("1");
//    tokens.push_back("+");
//    tokens.push_back("3");
//    tokens.push_back("*");
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");
    cout << evalRPN(tokens) << endl;
    return 0;
}
