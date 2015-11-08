/* ----------------------------------------------------------------------------
* Copyright & copy; 2015 Matthew Low <mcorelow@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

//Various functions using recursion

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

//prototypes
int abs(int);
int gcd(int,int);
int gcd_iterative(int, int);
int fibonacci(int, int a = 1, int b = 1);
	
int main(){
	int gnum1, gnum2, fnum;
	
	//gcd 
	cout << "Enter two ints and to find the gcd: ";
	cin >> gnum1 >> gnum2;
	cout << "GCD: " << gcd(gnum1,gnum2) << endl;
	cout << "GCD iterative: " << gcd_iterative(gnum1,gnum2) << endl;
	cout << endl;
	
	//fibonacci
	cout << "Enter an int to find the nth fibonacci number: ";
	cin >> fnum;
	cout << fibonacci(fnum) << endl;
return 0;
}

//--------------------------- GCD ----------------------------------- 

int abs(int x){
	if (x < 0){
		x = -x;
	}
	return x;	
}

int gcd(int a, int b){
	a = abs(a);
	b = abs(b);
	
	if (a == 0 || b == 0){
		return a + b;
	}
	
	if (a > b){
		return gcd(a-b,b);
	}
	
	return gcd(a,b-a);
}

int gcd_iterative(int a, int b){
	a = abs(a);
	b = abs(b);
	
	while (a != 0 && b != 0){
		if (a > b){
			a -= b;
		}
		else{
			b -= a;
		}
	}
	return a + b;
}


//--------------------------- Fibonacci -------------------------------- 

int fibonacci(int n, int a, int b)
{
   if (n == 1)
       return a;
   else if(n == 2){
	   return b;
   }
   else
       return fibonacci(n-1) + fibonacci(n-2);
}
