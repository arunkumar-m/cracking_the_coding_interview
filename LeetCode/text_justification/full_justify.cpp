/*
 * =====================================================================================
 *
 *       Filename:  full_justify.cpp
 *
 *        Version:  1.0
 *        Created:  12/25/2013 19:02:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

void printVecStr(vector<string> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

void printVecVecStr(vector<vector<string> > &v) {
    for (int i = 0; i < v.size(); i++) {
        printVecStr(v[i]);
    }
}

string formatLine(vector<string> line, int L, bool leftJustify) {
    if (line.size() == 1) {
        string ret = line[0];
        ret.append(L - line[0].size(), ' ');
        return ret;
    }
    if (!leftJustify) {
        int i = 0, len = 0, space_len = 0;
        for (int i = 0; i < line.size(); i++) {
            len += line[i].length();
        }
        space_len = L - len;
        while (space_len > 0) {
            if (i < line.size() - 1) {
                line[i] += " ";
                space_len--;
                i++;
            }
            else {
                i = 0;
            }
        }
        string ret;
        for (int i = 0; i < line.size(); i++) {
            ret += line[i];
        }
        return ret;
    }
    else {
        string ret;
        ret += line[0];
        int len = line[0].length();
        for (int i = 1; i < line.size(); i++) {
            ret += " " + line[i];
            len += 1 + line[i].length();
        }
        ret.append(L - len, ' ');
        return ret;
    }
}

vector<vector<string> > lines(vector<string> &words, int L) {
    int i = 0, len = 0;
    vector<vector<string> > ls;
    vector<string> line;
    while (i < words.size()) {
        if (len == 0) {
            line.push_back(words[i]);
            len = words[i].length();
        }
        else if (len <= L && len + 1 + words[i].length() <= L) {
            line.push_back(words[i]);
            len += 1 + words[i].length();
        }
        else {
            ls.push_back(line);
            len = 0;
            line.clear();
            i--;
        }
        i++;
    }
    if (line.size() > 0) ls.push_back(line);
    return ls;
}

vector<string> fullJustify(vector<string> &words, int L) {
    vector<vector<string> > ls = lines(words, L);
    vector<string> ret;
    for (int i = 0; i < ls.size() - 1; i++) {
        ret.push_back(formatLine(ls[i], L, false));
    }
    ret.push_back(formatLine(ls[ls.size() - 1], L, true));
    return ret;
}

int main() {
    vector<string> words;
    words.push_back("what");
    words.push_back("must");
    words.push_back("be");
    words.push_back("shall");
    words.push_back("be");
//    words.push_back("This");
//    words.push_back("is");
//    words.push_back("an");
//    words.push_back("example");
//    words.push_back("of");
//    words.push_back("text");
//    words.push_back("justification.");
    vector<string> ret = fullJustify(words, 12);
    printVecStr(ret);
    return 0;
}
