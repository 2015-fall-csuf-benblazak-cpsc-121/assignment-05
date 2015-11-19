#include <iostream>

using std::cout;
using std::endl;

int fib(int num){

	int nb4 = 1;
	int n = 0;
	int value = 1;

	if (num == 1)
		return 1;
	if (num == 2)
		return 1;
	else
	{
		for (int i = 1; i <= num; i++){

			value = nb4 + n;
			nb4 = n;
			n = value;
		}
	}

	return value;
}

int recfib(int num, int f1 = 1, int f2= 1){

	int sum = 0;

	for (int y = 0; y < num; y++){
		sum = f1 + f2;
		recfib(num--, f1 = f2, f2 = sum);
	}

	return sum;
}

int main(){

	recfib(5);

	system("pause");
	return 0;
}
