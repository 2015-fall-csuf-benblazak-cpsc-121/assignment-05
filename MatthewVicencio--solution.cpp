#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int fibonacci(int n);
int fibonacci_iterative(int x);
int fibonacci(int a){
	if (a == 0)
	{
		
		return 0;
	}

	if (a == 1)
	{
	
		return 1;
	}

	
		return fibonacci(a - 1) + fibonacci(a - 2);
}

int fibonacci_iterative(int f){
	if (f == 0)
	{
		return 0;
	}
	if (f == 1){

		return 1;
	}
	int f1 = 1;
	int f2 = 1;
	int result = 1;
	for (int i = 0; i <= f; i++){
		result = f1 + f2;
		f2 = f1;
		f2 = result;
		
	}
	return result;
}


int main(){
	int userInput;

	cout << "Enter a term to fibonacci-ize!";
	cin >> userInput;

	cout << "Calculated Recursively: " << fibonacci(userInput) << endl;
	cout << "Calculated Iteratively: " << fibonacci_iterative(userInput) << endl;

	system("PAUSE");



}
