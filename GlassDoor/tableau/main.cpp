#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    BST bst;
    cout << "insert 3\n";
    bst.insert(3);
    cout << "insert 4\n";
    bst.insert(4);
    cout << "insert 1\n";
    bst.insert(1);
    cout << "insert 2\n";
    bst.insert(2);
    bst.print();
    return 0;
}
