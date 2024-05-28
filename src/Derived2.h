#ifndef DERIVED2_H
#define DERIVED2_H

#include "Base.h"
#include <string>

class Derived2 : public Base {
public:
    std::string name;
    int value;

    Derived2() : name("DefaultName"), value(0) {}
    Derived2(const std::string& name, int value) : name(name), value(value) {}

    void display() const override {
        std::cout << "Derived2: " << name << ", " << value << std::endl;
    }

    void save(std::ofstream& out) const override {
        out << "Derived2 " << name << " " << value << std::endl;
    }

    void load(std::ifstream& in) override {
        in >> name >> value;
    }
};

#endif // DERIVED2_H
