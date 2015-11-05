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
int main()
{
	cout << gcd(8, 20) << endl;

	return 0;
}
