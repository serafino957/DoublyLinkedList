#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main() {
    DoublyLinkedList<int> list;

    list.addBack(10);
    list.addBack(20);
    list.addBack(30);

    list.display();
    list.displayReverse();

    cout << "Removing 20..." << endl;
    list.remove(20);

    list.display();
    list.displayReverse();

    return 0;
}
