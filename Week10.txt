// Week10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Item {
public:
    string name;
    int quantity;

    // Constructor
    Item() {
        name = "";
        quantity = 0;
    }
};

// Function to search for an item by name
void searchItem(Item items[], int size, string searchName) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (items[i].name == searchName) {
            cout << "Item found: " << items[i].name << " (Quantity: " << items[i].quantity << ")" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item not found in inventory." << endl;
    }
}

int main() {
    const int SIZE = 5;
    Item inventory[SIZE];

    // Input items
    cout << "Enter the name and quantity for each item:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Item " << i + 1 << " name: ";
        cin >> inventory[i].name;
        cout << "Item " << i + 1 << " quantity: ";
        cin >> inventory[i].quantity;
    }

    // Display all items
    cout << "\nInventory List:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << inventory[i].name << " - Quantity: " << inventory[i].quantity << endl;
    }

    // Search for an item
    string searchName;
    cout << "\nEnter an item name to search: ";
    cin >> searchName;
    searchItem(inventory, SIZE, searchName);

    return 0;
}

