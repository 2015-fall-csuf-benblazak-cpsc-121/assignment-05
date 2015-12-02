#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include<cmath>
using std::abs;

int gcd_iterative(int a, int b){
	a = abs(a);
	b = abs(b);

	while(a != 0 || b != 0){
		if(a == b){
			return a;
		}
		if(a > b){
			a -= b;
		}else{
			b -= a;
		}
	}

	return (a == 0)? a : b;
}

//recursive version
int gcd(int a, int b){
	a = abs(a);
	b = abs(b);
	if(a == 0 || b == 0){
		return a + b;
	}

	if(a > b){
		return gcd(a-b,b);
	}
	
	if(a < b){
		return gcd(a, b-a);
	}

	if(a == b){
		return a;
	}

}

int fibonacci_iterative(int n, int f1 = 1, int f2 = 1){
	if(n <= 2) {
		return 1;
	}
	
	int sum = 0;
	for(int i = 2; i < n; i++){
		 sum = f1 + f2;
		f1 = f2;
		f2 = sum;
	}
	return sum;

	
}

int fibonacci(int n, int f1 = 1, int f2 = 1){
	if( n <=  2 ){
		return 1;
	}

	return  fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
	/* Finding GCD
	int x,y;	
	cout << "Input 2 numbers: ";
	cin >> x >> y;
	cout << "GCD: " << gcd(x,y);
	*/
	
	// Fibonacci
	int num;
	cout << "Enter a number: ";
	cin >> num;
	cout << fibonacci_iterative(num);
	

	return 0;
}

