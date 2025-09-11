// Week4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	double x = 0, y = 0, result = 0;
	char op = 0;

	cout << "please enter the first number: ";
	cin >> x;

	cout << "Please enter the second number: ";
	cin >> y;

	cout << "please enter the operator: ";
	cin >> op;

	if (op == '+') {
		result = x + y;
	}
	else if (op == '-') {
		result = x - y;
	}
	else if (op == '*') {
		result = x * y;
	}
	else if (op == '/') {
		result = x / y;
	}
	else if (op == '%') {
		result = fmod(x, y);
	}
	else {
		cout << "The operator is invalid. Try +, -, *, /, %\n";
	}
	
	cout << "The result is " << result << endl;
	return 0;
}