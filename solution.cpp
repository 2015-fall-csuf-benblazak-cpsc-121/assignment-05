/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Jaemin Jin <jaemin_95@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Do recursion/iteration for the following: Euclid's algorithm, Fibonacci, Roman Numerals, and Integers to Words.
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

// #1: Function Prototypes for "Euclid's Algorithm (GCD)"

// int gcd_iterative(int a, int b);
// int gcd(int a, int b);
// int abs(int a);

// #1: Function Definitions

// I did this function on my own this time.
int gcd_iterative(int a, int b)                                 // Iterative form
{
    a = abs(a);
    b = abs(b);
    
    while (a == 0 && b == 0)
        if (a > b)
            a -= b;
        else
            b -= a;
    return a+b;
}

// Referenced during the lecture(meeting-11-1.mp4).
int gcd(int a, int b)                                           // Recursive form
{
    a = abs(a);
    b = abs(b);
    
    if (a == 0 || b == 0)
        return a+b;
    
    if (a > b)
        return gcd(a-b, b);
    else
        return gcd(a,b-a);
}

int abs(int a)
{
    return (a >= 0) ? a: -a;
}

// #2: Function Prototypes for Fibonacci

// int fibonacci_iterative(int n, int f1 = 1, int f2 = 1);
// int fibonacci(int n, int f1 = 1, int f2 = 1);

// #2: Function Definitions

// Referenced and rephrased "Fibonacci in C++ " on http://talkbinary.com/programming/c/fibonacci-in-c/ after many serious attempts on my own these functions.
int fibonacci_iterative(int n, int f1 = 1, int f2 = 1)           // Iterative form
{
    if ( n == 1 || n == 2)
        return f1 || f2;
     
    int fn = 0;
     
    for (int i = 3; i <= n; i++)
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
     
    return fn;
     
 }

int fibonacci(int n, int f1 = 1, int f2 = 1)                     // Recursive form
{
    if ( n == 1 || n == 2)
        return f1 || f2;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// #3: Function Definitions

// Referenced on github on Assignment 5.
string int_to_roman_iterative(int i)                             // Iterative form
{
    const string numerals[] =
    {
        "M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
    };
    const int values[] =
    {
        1000, 900,  500, 400,  100, 90,   50,  40,   10,  9,    5,   4,    1,
    };
    
    if (i < 0)
        return "ERROR: too small";
    if (i >= 4000)
        return "ERROR: too large";
    
    string ret = "";
    
    for (int a = 0; a < sizeof(values)/sizeof(int); a++)
    {
        while (i >= values[a])
        {
            ret += numerals[a];
            i -= values[a];
        }
    }
    return ret;
}

string int_to_roman(int i)                                       // Recursive form
{
    const string numerals[] =
    {
        "M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
    };
    const int values[] =
    {
        1000, 900,  500, 400,  100, 90,   50,  40,   10,  9,    5,   4,    1,
    };
    
    if (i < 0)
        return "ERROR: too small";
    if (i >= 4000)
        return "ERROR: too large";
    
    return int_to_roman(i - 1);
}

// Main function
int main()
{
    // Euclid's Algorithm (GCD)
    cout << "Euclid Algorithm: " << endl;
    cout << endl;
    cout << "Iterative: " << gcd_iterative(4,13) << endl;
    cout << "Recursion: " << gcd(3,12) << endl;
    cout << endl;
    
    // Fibonacci
    cout << "Fibonacci" << endl;
    cout << endl;
    cout << "Iterative: " << fibonacci_iterative(7) << endl;
    cout << "Recursion: " << fibonacci(7) << endl;
    cout << endl;
    
    // Roman Numerals
    cout << "Roman Numerals " << endl;
    cout << endl;
    cout << "Iterative: " << int_to_roman_iterative(10) << endl;
    cout << "Recursion: " << int_to_roman(10) << endl;
    
    return 0;
}
