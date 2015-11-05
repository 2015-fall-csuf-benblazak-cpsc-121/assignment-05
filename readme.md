/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Duy Nguyen <andy21996@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */


#include "stdafx.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
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
	cout << gcd(10, 20) << endl;
	cout << gcd_iterative(10, 20) << endl;

	return 0;
}
