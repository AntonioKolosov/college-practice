#ifndef CONTAINER_H
#define CONTAINER_H

template <typename T>
class Container {
public:
    virtual ~Container() {}

    virtual void insert(const T& item) = 0;
    virtual void remove(const T& item) = 0;
    virtual bool isEmpty() const = 0;
    virtual void print() const = 0;
};

#endif // CONTAINER_H
