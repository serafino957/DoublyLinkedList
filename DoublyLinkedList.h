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
    // Konstruktor i destruktor
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Podstawowe metody
    void addFront(T data);        // Dodaj element na początek
    void addBack(T data);         // Dodaj element na koniec
    void remove(T data);          // Usuń element z listy
    void display() const;         // Wyświetl listę od początku
    void displayReverse() const;  // Wyświetl listę od końca
    void clear();                 // Wyczyść listę

    // ------------------ ITERATOR ------------------
    // Wewnętrzna klasa iteratora do przeglądania listy
    class iterator {
        Node* current;
    public:
        iterator(Node* node) : current(node) {}

        iterator& operator++() { current = current->next; return *this; }
        iterator& operator--() { current = current->prev; return *this; }
        T& operator*() { return current->data; }
        bool operator!=(const iterator& other) const { return current != other.current; }
    };

    iterator begin() { return iterator(head); }   // Zwraca iterator na początek listy
    iterator end() { return iterator(nullptr); }  // Zwraca iterator na koniec listy
};

#include "DoublyLinkedList.tpp"

#endif

// Update 2: Added iterator pattern
