/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Duy Nguyen <andy21996@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

Fibonacci

#include "stdafx.h"
#include <iostream>
using std::cout;

int fib(int a)
{
	if (a == 1 || a == 2)
		return 1;

	return fib(a - 1) + fib(a-2);
}

int main()
{
	for (int i = 1; i < 10; i++)
		cout << fib(i) << " ";

	return 0;
}

GCD

#include "stdafx.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

int gcd(int a, int b)
{
	a = abs(a);
	b = abs(b);

	if (a == 0 || b == 0)
		return a + b;
	
	if (a > b)
		return gcd(a - b, b);
	else
		return gcd(a, b - a);
}

int gcd_iterative(int a, int b)
{
	int minNum = a > b ? b : a;
	int gcd = 1;
	for (int i = 1; i <= minNum; i++)
	{
		if (a % i == 0 && b % i == 0)
			gcd = i;
	}

	return gcd;	
}

int main()
{
	cout << gcd(8, 20) << endl;
	cout << gcd_iterative(8, 20) << endl;

	return 0;
}

Int to Roman

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

string int_to_roman_iterative(int i) 
{
	const string numerals[] = 
	{
		"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
	};
	const int values[] = 
	{
		1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1,
	};

	if (i < 0)
		return "ERROR: too small";
	if (i >= 4000)
		return "ERROR: too large";

	string ret = "";
	int a = 0;
	int noOfElement = sizeof(values) / sizeof(int);
	while (a < noOfElement && i > 0)
	{
		while (i >= values[a]) 
		{
			ret += numerals[a];
			i -= values[a];
		}
		a++;
	}

	return ret;
}

string int_to_roman(int number)
{
	if (number < 1) return "";
	if (number >= 1000) return "M" + int_to_roman(number - 1000);
	if (number >= 900) return "CM" + int_to_roman(number - 900);
	if (number >= 500) return "D" + int_to_roman(number - 500);
	if (number >= 400) return "CD" + int_to_roman(number - 400);
	if (number >= 100) return "C" + int_to_roman(number - 100);
	if (number >= 90) return "XC" + int_to_roman(number - 90);
	if (number >= 50) return "L" + int_to_roman(number - 50);
	if (number >= 40) return "XL" + int_to_roman(number - 40);
	if (number >= 10) return "X" + int_to_roman(number - 10);
	if (number >= 9) return "IX" + int_to_roman(number - 9);
	if (number >= 5) return "V" + int_to_roman(number - 5);
	if (number >= 4) return "IV" + int_to_roman(number - 4);
	if (number >= 1) return "I" + int_to_roman(number - 1);
}
int main()
{
	cout << int_to_roman_iterative(3691) << endl;
	cout << int_to_roman(3691) << endl;

	return 0;
}
