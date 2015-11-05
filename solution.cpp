/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 James Mabe <jamespmabe@gmail.com>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * this program includes recursive and iterative versions of GCD, fibonacci, and the recursive Roman Numerals solution.
 */

#include <iostream>
using std::cout;
using std::endl;

int fibonacci(int n){
    if (n<=2){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int fibonacci_iterative(int n, int f1 = 1, int f2= 1){
    if (n<=2){
        return 1;
    }
    int c;
    for (int i = 0; i < n - 2; i++){
        c = f1+f2;
        f2 = f1;
        f1 = c;
    }
    return f1;
}

int main(){
    cout << fibonacci_iterative(6) << endl;
    
    for (int i = 1; i <10; i++)
    cout << fibonacci(i) << " ";
}
