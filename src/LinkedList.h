#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
#include "Container.h"
#include "Base.h"
#include "Derived1.h"
#include "Derived2.h"

template <typename T>
class LinkedList : public Container<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList();

    void insert(const T& item) override;
    void remove(const T& item) override;
    bool isEmpty() const override;
    void print() const override;

    Node* getTail() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}

        T& operator*() const {
            return current->data;
        }

        Node* operator->() {
            return current;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }
};

template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::insert(const T& item) {
    Node* newNode = new Node(item);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template <typename T>
void LinkedList<T>::remove(const T& item) {
    Node* current = head;
    while (current) {
        if (current->data == item) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void LinkedList<T>::print() const {
    Node* current = head;
    while (current) {
        current->data->display(); // Вызов метода display() через указатель на Base
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::getTail() const {
    return tail;
}

template <typename T>
void LinkedList<T>::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    Node* current = head;
    while (current) {
        current->data->save(out);
        current = current->next;
    }
    out.close();
}

template <typename T>
void LinkedList<T>::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    std::string type;
    while (in >> type) {
        Base* obj = nullptr;
        if (type == "Derived1") {
            obj = new Derived1();
        } else if (type == "Derived2") {
            obj = new Derived2();
        }
        if (obj) {
            obj->load(in);
            insert(obj);
        }
    }
    in.close();
}

#endif // LINKEDLIST_H
