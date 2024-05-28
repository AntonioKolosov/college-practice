#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <algorithm>
#include "Container.h"
#include "Base.h"
#include "DynamicArray.h"

template <typename T>
class PriorityQueue {
private:
    DynamicArray<T> data;

    void heapifyUp(int index) {
        if (index && data[index] > data[parent(index)]) {
            std::swap(data[index], data[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        int leftChild = left(index);
        int rightChild = right(index);
        int largest = index;

        if (leftChild < data.getSize() && data[leftChild] > data[largest])
            largest = leftChild;

        if (rightChild < data.getSize() && data[rightChild] > data[largest])
            largest = rightChild;

        if (largest != index) {
            std::swap(data[index], data[largest]);
            heapifyDown(largest);
        }
    }

    int parent(int index) { return (index - 1) / 2; }
    int left(int index) { return (2 * index + 1); }
    int right(int index) { return (2 * index + 2); }

public:
    void push(const T& item) {
        data.insert(item);
        heapifyUp(data.getSize() - 1);
    }

    void pop() {
        if (!data.isEmpty()) {
            data[0] = data[data.getSize() - 1];
            data.remove(data[data.getSize() - 1]);
            heapifyDown(0);
        } else {
            std::cout << "Priority queue is empty." << std::endl;
        }
    }

    T top() const {
        if (!data.isEmpty()) {
            return data[0];
        } else {
            throw std::runtime_error("Priority queue is empty.");
        }
    }

    bool isEmpty() const {
        return data.isEmpty();
    }

    void print() const {
        data.print();
    }

    void saveToFile(const std::string& filename) const {
        data.saveToFile(filename);
    }

    void loadFromFile(const std::string& filename) {
        data.loadFromFile(filename);
    }

    using Iterator = typename DynamicArray<T>::Iterator;

    Iterator begin() {
        return data.begin();
    }

    Iterator end() {
        return data.end();
    }
};

#endif // PRIORITYQUEUE_H
