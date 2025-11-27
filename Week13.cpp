// Week13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

using namespace std;

// Base class
class User {
public:
    virtual void accessLevel() {
        cout << "General Access\n";
    }
};

// Derived from User
class Employee : public User {
public:
    void accessLevel() override {
        cout << "Employee Access\n";
    }
};

// Derived from Employee
class InventoryManager : public Employee {
public:
    void accessLevel() override {
        cout << "Full Inventory Management Access\n";
    }
};

int main() {
    InventoryManager mgr;
    mgr.accessLevel(); // Should print: Full Inventory Management Access
    return 0;
}
