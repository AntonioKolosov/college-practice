#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template <typename T>
class Stack {
private:
    LinkedList<T> list;

public:
    void push(const T& item) {
        list.insert(item);
    }

    void pop() {
        if (!list.isEmpty()) {
            list.remove(list.getTail()->data); // Удаляем последний элемент
        } else {
            std::cout << "Stack is empty." << std::endl;
        }
    }

    T top() const {
        if (!list.isEmpty()) {
            return list.getTail()->data; // Возвращаем последний элемент
        } else {
            throw std::runtime_error("Stack is empty.");
        }
    }

    bool isEmpty() const {
        return list.isEmpty();
    }

    void print() const {
        list.print();
    }

    void saveToFile(const std::string& filename) const {
        list.saveToFile(filename);
    }

    void loadFromFile(const std::string& filename) {
        list.loadFromFile(filename);
    }

    using Iterator = typename LinkedList<T>::Iterator;

    Iterator begin() {
        return list.begin();
    }

    Iterator end() {
        return list.end();
    }
};

#endif // STACK_H
