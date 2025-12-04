// Week14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

using namespace std;

class Product {
    int id;
    string name;
    float price;
public:
    Product(int i, string n, float p) : id(i), name(n), price(p) {
        cout << "Constructor called\n";
    }
    ~Product() {
        cout << "Destructor called\n";
    }
    void printDetails() {
        cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << endl;
    }
};

int main() {
    Product p(101, "Notebook", 4.99);
    p.printDetails();
    return 0;
}
