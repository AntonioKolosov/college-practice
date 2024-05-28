#include "DynamicArray.h"

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
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
