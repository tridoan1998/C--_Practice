//============================================================================
// Name        : ReviewFor22C.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string>
#include "linklist.h"

using namespace std;

int main() {
	Linklist B;

	for (int number = 2; number <= 100; number++)
	{
		int count = 0;
		for (int divitor = 1; divitor <= number; divitor++)
		{
			if(number % divitor == 0)
			{
				count++;
			}
		}
		if(count <= 2)
		{
			cout << number << "is prime.";
			cout << endl;
		}
	}


	return 0;
}
