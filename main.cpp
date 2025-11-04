#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

// Wzorzec projektowy: Fabryka (Factory Pattern)
template <typename T>
class ListFactory {
public:
    static DoublyLinkedList<T>* createList() {
        return new DoublyLinkedList<T>();
    }
};

int main() {
    // Tworzenie listy przez fabrykę
    auto list = ListFactory<int>::createList();

    // Dodawanie elementów
    list->addBack(10);
    list->addBack(20);
    list->addBack(30);

    // Wyświetlanie listy
    list->display();
    list->displayReverse();

    // Testowanie iteratora
    cout << "Iterating using iterator: ";
    for (auto it = list->begin(); it != list->end(); ++it)
        cout << *it << " ";
    cout << endl;

    // Usuwanie elementu
    cout << "Removing 20..." << endl;
    list->remove(20);

    // Wyświetlanie ponownie po usunięciu
    list->display();
    list->displayReverse();

    // Czyszczenie pamięci
    delete list;

    return 0;
}
// Update 5: Added iterator + factory pattern
