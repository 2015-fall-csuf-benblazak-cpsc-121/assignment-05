/*# -----------------------------------------------------------------------------
# Copyright &copy; 2015 Paul Sihavong <paul.sihavong@csu.fullerton.edu>
# Released under the[MIT License](http://opensource.org/licenses/MIT)
# -----------------------------------------------------------------------------*/

/*Program Description
*The purpose of this program is to demonstrate the use of recursive and iterative
functions. Also examining the code, there is a difference in the method of
iterative and recursive functions.*/

#include <iostream>
#include <cmath>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int gcd_iterative(int a, int b){
	a = abs(a);
	b = abs(b);
	if (a > b)
		a -= b;
	else if (a < b)
		b -= a;
	else if (a == 0)
		return b;
	else if (b == 0)
		return a;
}

int gcd(int a, int b) {
	a = abs(a);
	b = abs(b);
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	else if (a > b)
		return gcd(a - b, b);
	else if (a < b)
		return gcd(a, b - a);
}

string int_to_RN(int n){ // This recursion will be referring to its iterative
	if (n > 1000){		 // form from Assignment 1
		int_to_RN(n - 1000);
		return "M";
	}
	else if (n > 900){
		int_to_RN(n - 900);
		return "CM";
	}
	else if (n > 500){
		int_to_RN(n - 500);
		return "D";
	}
	else if (n > 400){
		int_to_RN(n - 400);
		return "DC";
	}
	else if (n > 100){
		int_to_RN(n - 100);
		return "C";
	}
	else if (n > 90){
		int_to_RN(n - 90);
		return "XC";
	}
	else if (n > 50){
		int_to_RN(n - 50);
		return "L";
	}
	else if (n > 40){
		int_to_RN(n - 40);
		return "LX";
	}
	else if (n > 10){
		int_to_RN(n - 10);
		return "X";
	}
	else if (n > 5){
		int_to_RN(n - 5);
		return "V";
	}
	else if (n > 4){
		int_to_RN(n - 4);
		return "IV";
	}
	else if (n > 1){
		int_to_RN(n - 1);
		return "I";
	}
	
}

int fibonacci_iterative(int n);
int fibonacci(int n);

int main(){
	int a = 6;
	int b = 8;
	int c = 7; //int to demonstrate int_to_RN
	cout << "gcd_iterative(a, 0) = " << gcd_iterative(a, 0) << endl;
	cout << "gcd_iterative(0, b) = " << gcd_iterative(0, b) << endl;
	cout << "gcd_iterative(a, b) = " << gcd_iterative(a, b) << endl;
	cout << "gcd(a, 0) = " << gcd(a, 0) << endl;
	cout << "gcd(0, b) = " << gcd(0, b) << endl;
	cout << "gcd(a, b) = " << gcd(a, b) << endl;
	cout << "fibonacci_iterative(a) = " << fibonacci_iterative(a) << endl;
	cout << "fibonacci(a) = " << fibonacci(a) << endl;
	cout << "int_to_RN(c) = " << int_to_RN(c) << endl;
	system("PAUSE");
	return 0;
}

int fibonacci_iterative(int n){
	int f1 = 1, f2 = 1;
	if (n == f1 || n == f2)
		return 1;
	else
		return ((pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5)) ;
}

int fibonacci(int n){
	int f1 = 1, f2 = 1;
	if (n == 1 || n == 2)
		return 1;
	else if (n >= 3)
		return fibonacci(n - 1) + fibonacci(n - 2);
}

