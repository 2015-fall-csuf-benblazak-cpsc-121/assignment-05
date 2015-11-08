/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Matthew Low <mcorelow@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/*
 * Various functions using recursion
 */

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

//prototypes
int fibonacci(int, int a = 1, int b = 1);
	
int main(){
	int num;
	cin >> num;
	cout << fibonacci(num) << endl;
return 0;
}

//function that calcalates the nth fibonacci number
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
