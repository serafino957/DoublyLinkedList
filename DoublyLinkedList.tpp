// Implementacja metod szablonu listy dwukierunkowej

#include <iostream>
using namespace std;

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

// Dodaj na początek
template <typename T>
void DoublyLinkedList<T>::addFront(T data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Dodaj na koniec
template <typename T>
void DoublyLinkedList<T>::addBack(T data) {
    Node* newNode = new Node(data);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Usuń element
template <typename T>
void DoublyLinkedList<T>::remove(T data) {
    Node* cur = head;
    while (cur) {
        if (cur->data == data) {
            if (cur->prev) cur->prev->next = cur->next;
            else head = cur->next;

            if (cur->next) cur->next->prev = cur->prev;
            else tail = cur->prev;

            delete cur;
            return;
        }
        cur = cur->next;
    }
}

// Wyświetl od początku
template <typename T>
void DoublyLinkedList<T>::display() const {
    Node* temp = head;
    cout << "List forward: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Wyświetl od końca
template <typename T>
void DoublyLinkedList<T>::displayReverse() const {
    Node* temp = tail;
    cout << "List reverse: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Wyczyść listę
template <typename T>
void DoublyLinkedList<T>::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
}
