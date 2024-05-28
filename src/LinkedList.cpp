#include "LinkedList.h"

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
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
