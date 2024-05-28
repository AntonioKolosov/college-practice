#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <fstream>

class Base {
public:
    virtual ~Base() {}
    virtual void display() const = 0; // Чисто виртуальный метод
    virtual void save(std::ofstream& out) const = 0; // Метод для сохранения
    virtual void load(std::ifstream& in) = 0; // Метод для загрузки
};

#endif // BASE_H
