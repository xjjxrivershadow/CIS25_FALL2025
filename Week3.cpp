// Week3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	string itemName;
	int quantity;
	float cost;

	cout << "Enter the item name you wish to checkout: ";
	cin >> itemName;
	cout << "\n Enter how quantity: ";
	cin >> quantity;
	cout << "\n Enter the cost of the item: ";
	cin >> cost;

	cout << "The total cost for " << itemName << ": $" << (quantity * cost) << endl;
	return 0;
}
