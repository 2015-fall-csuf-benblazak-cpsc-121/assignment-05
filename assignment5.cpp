/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
                        Samir Mandal <mandalsamir@fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

//Euclid GCD algorithm 

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);

    if (a == 0 || b == 0)//if a or b is non-zero, return whichever is non-zero
      return a+b;

    if (a > b)
        return gcd(a-b, b);//recursion

    return gcd(a, b-a);//recursion
}


//Fibonacci series

int fibonacci(int n){

  if (n < 1)
      return 0;

  if (n < 3)
      return 1;

  return fibonacci(n-1) + fibonacci(n-2);//recursion
}
