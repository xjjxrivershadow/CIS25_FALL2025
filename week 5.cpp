// week 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include<stdio.h>

using namespace std;

void square(int n)
{
	cout << pow(n, 2) << " ";
}

void squareroot(int n)
{
	cout << sqrt(n) << " ";
}

void number(int n) {
	cout << n << " ";
}

int main()
{
	for (int i = 1; i <= 81; i++)
	{
		number(i);
		square(i);
		squareroot(i);
		cout << endl;

	}

	return 0;
}

