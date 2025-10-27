// Third commit - updated header comment


#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
using namespace std;

// Szablon listy dwukierunkowej
template <typename T>
class DoublyLinkedList {
private:
    // Wewnętrzna struktura węzła
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void addFront(T data);  // Dodaj element na początek
    void addBack(T data);   // Dodaj element na koniec
    void remove(T data);    // Usuń element z listy
    void display() const;   // Wyświetl listę od początku
    void displayReverse() const; // Wyświetl listę od końca
    void clear();           // Wyczyść listę
};

#include "DoublyLinkedList.tpp"

#endif

// Update 2: Header minor edit
