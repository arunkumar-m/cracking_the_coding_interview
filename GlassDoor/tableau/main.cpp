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
    cout << "lookup 4\n";
    for (int i = 0; i < 10; i++) {
      cout << i << " found? " << bst.lookup(i) << endl;
    }
    bst.print();
    cout << "delete 3\n";
    bst.remove(3);
    bst.print();
    cout << "delete 1\n";
    bst.remove(1);
    bst.print();
    cout << "delete 4\n";
    bst.remove(4);
    bst.print();
    cout << "delete 2\n";
    bst.remove(2);
    bst.print();
    return 0;
}
