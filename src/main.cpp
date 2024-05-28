#include <iostream>
#include "Container.h"
#include "LinkedList.h"
#include "DynamicArray.h"
#include "Base.h"
#include "Derived1.h"
#include "Derived2.h"
#include "Stack.h"
#include "PriorityQueue.h"

void showMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Add object\n";
    std::cout << "2. Get object\n";
    std::cout << "3. Remove object\n";
    std::cout << "4. Print container\n";
    std::cout << "5. Save to file\n";
    std::cout << "6. Load from file\n";
    std::cout << "0. Exit\n";
}

void showContainerMenu() {
    std::cout << "Select container type:\n";
    std::cout << "1. Stack\n";
    std::cout << "2. Priority Queue\n";
}

template <typename Container>
void printWithIterator(Container& container) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        (*it)->display();
    }
}

int main() {
    int containerChoice;
    showContainerMenu();
    std::cin >> containerChoice;

    if (containerChoice == 1) {
        Stack<Base*> container;
        int choice;
        bool exit = false;

        while (!exit) {
            showMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    std::cout << "Add object selected.\n";
                    std::cout << "Select type: 1. Derived1 2. Derived2: ";
                    int type;
                    std::cin >> type;
                    if (type == 1) {
                        std::string name;
                        int value;
                        std::cout << "Enter name and value for Derived1: ";
                        std::cin >> name >> value;
                        container.push(new Derived1(name, value));
                    } else if (type == 2) {
                        std::string name;
                        int value;
                        std::cout << "Enter name and value for Derived2: ";
                        std::cin >> name >> value;
                        container.push(new Derived2(name, value));
                    } else {
                        std::cout << "Invalid type.\n";
                    }
                    break;
                }
                case 2:
                    std::cout << "Get object selected.\n";
                    try {
                        Base* top = container.top();
                        top->display();
                    } catch (const std::runtime_error& e) {
                        std::cout << e.what() << std::endl;
                    }
                    break;
                case 3: {
                    std::cout << "Remove object selected.\n";
                    container.pop();
                    break;
                }
                case 4:
                    std::cout << "Print container selected.\n";
                    printWithIterator(container);
                    break;
                case 5: {
                    std::cout << "Save to file selected.\n";
                    container.saveToFile("stack.txt");
                    break;
                }
                case 6: {
                    std::cout << "Load from file selected.\n";
                    container.loadFromFile("stack.txt");
                    break;
                }
                case 0:
                    exit = true;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        }
    } else if (containerChoice == 2) {
        PriorityQueue<Base*> container;
        int choice;
        bool exit = false;

        while (!exit) {
            showMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    std::cout << "Add object selected.\n";
                    std::cout << "Select type: 1. Derived1 2. Derived2: ";
                    int type;
                    std::cin >> type;
                    if (type == 1) {
                        std::string name;
                        int value;
                        std::cout << "Enter name and value for Derived1: ";
                        std::cin >> name >> value;
                        container.push(new Derived1(name, value));
                    } else if (type == 2) {
                        std::string name;
                        int value;
                        std::cout << "Enter name и value for Derived2: ";
                        std::cin >> name >> value;
                        container.push(new Derived2(name, value));
                    } else {
                        std::cout << "Invalid type.\n";
                    }
                    break;
                }
                case 2:
                    std::cout << "Get object selected.\n";
                    try {
                        Base* top = container.top();
                        top->display();
                    } catch (const std::runtime_error& e) {
                        std::cout << e.what() << std::endl;
                    }
                    break;
                case 3: {
                    std::cout << "Remove object selected.\n";
                    container.pop();
                    break;
                }
                case 4:
                    std::cout << "Print container selected.\n";
                    printWithIterator(container);
                    break;
                case 5: {
                    std::cout << "Save to file selected.\n";
                    container.saveToFile("priority_queue.txt");
                    break;
                }
                case 6: {
                    std::cout << "Load from file selected.\n";
                    container.loadFromFile("priority_queue.txt");
                    break;
                }
                case 0:
                    exit = true;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        }
    } else {
        std::cout << "Invalid container type.\n";
    }

    std::cout << "Exiting program.\n";
    return 0;
}
