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
