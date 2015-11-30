/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Randy Tanizawa <rtanizawa@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A demonstration of recursive and iterative functions.
*   Including: Greatest Common Denominator
               Fibonacci Numbers
               Integers to Roman Numerals
               Integers to Alphabetized Integers
               Magic Number Riddle
*/

#include <iostream>
#include <cmath>
#include <string>

using std::cout;
using std::endl;
using std::abs;
using std::string;

int gcd( int x, int y );
int gcd_iter( int x , int y );
int fib( int f , int f1 = 1, int f2 = 1);
int fib_iter( int f );
string int_to_roman( int r , string rn = "");
string int_to_word( int w, string nw = "");
int magic( int m );

int main()
{
    cout << gcd(24,600) << endl;
    cout << gcd_iter(24,600) << endl;
    cout << fib(11) << endl;
    cout << fib_iter(11) << endl;
    cout << int_to_word(18818) << endl;
    magic(12);

    return 0;
}

int gcd( int x, int y )
{
    x = abs(x);
    y = abs(y);

    if( x == 0 || y == 0 )
        return x+y;

    if( x > y )
        return gcd( x-y , y);
    else
        return gcd( x , y-x );
}

int gcd_iter( int x , int y )
{
    x = abs(x);
    y = abs(y);

    while(x && y)
        if( x > y )
            x -= y;
        else
            y -= x;

    return x+y;
}

int fib( int f , int f1, int f2 )
{
    if( f <= 2 )
        return f2;
    else
    {
        int f3;
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
        f--;
        if( f != 0)
            return fib( f , f1 , f2 );
        else
            return f3;
    }
}

int fib_iter( int f )
{
    int f1 = 1;
    int f2 = 1;
    int f3;
    int n = 3;

    if( f <= 2)
        return f2;
    else
        while( n < (f + 1))
        {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
            n++;
        }
    return f3;
}

string int_to_roman( int r , string rn)
{
    if( r > 4000)
        return "Out of bounds";
    else if( r >= 1000 )
        return int_to_roman( r - 1000, rn + "M" );
    else if( r  >= 900 )
        return int_to_roman( r - 900, rn + "CM" );
    else if( r >= 500 )
        return int_to_roman( r - 500, rn + "D" );
    else if( r >= 400 )
        return int_to_roman( r - 500, rn + "CD" );
    else if( r >= 100 )
        return int_to_roman( r - 100, rn + "C" );
    else if( r >= 90 )
        return int_to_roman( r - 90, rn + "XC" );
    else if( r >= 50 )
        return int_to_roman( r - 50, rn + "L" );
    else if( r >= 40 )
        return int_to_roman( r - 40, rn + "XL" );
    else if( r >= 10 )
        return int_to_roman( r - 10, rn + "X" );
    else if( r >= 9 )
        return int_to_roman( r - 9, rn + "IX" );
    else if( r >= 5 )
        return int_to_roman( r - 5, rn + "V" );
    else if( r >= 4 )
        return int_to_roman( r - 4, rn + "IV" );
    else if ( r >= 1 )
        return int_to_roman( r - 1, rn + "I" );
    else
        return rn;
}

string int_to_word( int w, string nw )
{
    const string ones[11] = {"","one","two","three","four","five","six","seven","eight","nine","ten"};
    const string teens[10] = {"","eleven","twelve","thirteen","fourteen","fifteen",
                             "sixteen","seventeen","eighteen","nineteen"};
    const string tens[10] = {"","ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};

    string n;

    if( ( w / 1000000 ) >= 1 )
    {
        n = ones[w/1000000];
        w = w - ( (w/1000000) * 1000000 );
        return int_to_word( w , nw + n + "million " );
    }
    else if( ( w / 100000 ) >= 1 )
    {
        n = ones[ w / 100000 ];
        w = w - ( (w/100000) * 100000 );
        return int_to_word( w , nw + n + "hundred-thousand " );
    }
    else if( ( w / 10000 ) > 1 )
    {
        n = tens[ w / 10000 ];
        w = w - ( (w/10000) * 10000);
        return int_to_word( w , nw + n + " " );
    }
    else if( ( w / 10000 ) == 1 )
    {
        n = teens[ (w - 10000) / 1000 ];
        w = w - 10000;
        w = w - ((w/1000) * 1000 );
        return int_to_word( w , nw + n + " " + "thousand " );
    }
    else if( (w/1000) >= 1 )
    {
        n = ones[ w / 1000 ];
        w = w - ( (w/1000) * 1000 );
        return int_to_word( w , nw + n + " " + "thousand " );
    }
    else if( (w/100) >= 1 )
    {
        n = ones[ w / 100 ];
        w = w - ( (w/100) * 100 );
        return int_to_word( w , nw + n + " " + "hundred " );
    }
    else if( (w/10) > 1 )
    {
        n = tens[ w / 10 ];
        w = w - ( (w/10) * 10 );
        return int_to_word( w , nw + n );
    }
    else if( (w/10) == 1 )
    {
        n = teens[ w - 10 ];
        return nw + n;
    }
    else
    {
        n = ones[ w / 1 ];
        w = w - ( w/1 );
        return nw + n;
    }
}

int magic( int m )
{
    string _length = int_to_word( m );
    int length_ = _length.length();
    if( length_ == m )
    {
        cout << "4 is the magic number" << endl;
        return 0;
    }
    else
    {
        cout << m << " is " << length_ << endl;
        return magic( length_ );
    }
}


