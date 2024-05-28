#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <fstream>
#include "Container.h"
#include "Base.h"
#include "Derived1.h"
#include "Derived2.h"

template <typename T>
class DynamicArray : public Container<T> {
private:
    T* data;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity);

public:
    DynamicArray();
    ~DynamicArray();

    void insert(const T& item) override;
    void remove(const T& item) override;
    bool isEmpty() const override;
    void print() const override;

    size_t getSize() const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    class Iterator {
    private:
        T* current;
    public:
        Iterator(T* ptr) : current(ptr) {}

        T& operator*() const {
            return *current;
        }

        T* operator->() {
            return current;
        }

        Iterator& operator++() {
            ++current;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() {
        return Iterator(data);
    }

    Iterator end() {
        return Iterator(data + size);
    }
};

template <typename T>
DynamicArray<T>::DynamicArray() : data(nullptr), size(0), capacity(2) {
    data = new T[capacity];
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <typename T>
void DynamicArray<T>::resize(size_t newCapacity) {
    T* newData = new T[newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename T>
void DynamicArray<T>::insert(const T& item) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    data[size++] = item;
}

template <typename T>
void DynamicArray<T>::remove(const T& item) {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == item) {
            for (size_t j = i; j < size - 1; ++j) {
                data[j] = data[j + 1];
            }
            --size;
            if (size > 0 && size == capacity / 4) {
                resize(capacity / 2);
            }
            return;
        }
    }
}

template <typename T>
bool DynamicArray<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
void DynamicArray<T>::print() const {
    for (size_t i = 0; i < size; ++i) {
        data[i]->display(); // Вызов метода display() через указатель на Base
    }
    std::cout << std::endl;
}

template <typename T>
size_t DynamicArray<T>::getSize() const {
    return size;
}

template <typename T>
T& DynamicArray<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
void DynamicArray<T>::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    for (size_t i = 0; i < size; ++i) {
        data[i]->save(out);
    }
    out.close();
}

template <typename T>
void DynamicArray<T>::loadFromFile(const std::string& filename) {
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

#endif // DYNAMICARRAY_H
