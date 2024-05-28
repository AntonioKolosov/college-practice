#ifndef DERIVED1_H
#define DERIVED1_H

#include "Base.h"
#include <string>

class Derived1 : public Base {
public:
    std::string name;
    int value;

    Derived1() : name("DefaultName"), value(0) {}
    Derived1(const std::string& name, int value) : name(name), value(value) {}

    void display() const override {
        std::cout << "Derived1: " << name << ", " << value << std::endl;
    }

    void save(std::ofstream& out) const override {
        out << "Derived1 " << name << " " << value << std::endl;
    }

    void load(std::ifstream& in) override {
        in >> name >> value;
    }
};

#endif // DERIVED1_H
