#include <iostream>
#include <vector>
#include <string>
using namespace std;

int fact(int n)
{
    return n > 1 ? fact(n - 1) * n : 1;
}


void  print_Spaces( int left, int right )
{
    for( int i = left ; i <= right ; i++ )
        cout << "  ";
}

int Coefficient(int num, int r_value)   // r_value is row value
{
    return ( fact( num )/(fact( r_value )*fact(num-r_value)) );
}

int main()
{
    int r_max ;

    cout << "Enter the number of rows of Pascal's Triangle\n";
    cin >> r_max;

   if(r_max < 0 )
    {
        cout<<"ERROR NUMBER MUST BE GREATER THAN ZERO"<<endl;       ///Could also check for whole numbers
        return 0;
    }

    for( int r = 0; r < r_max; r++ )
    {
         print_Spaces( r, r_max );    /// prints spaces from left to right

        for(int  i = 0; i <= r; i++ )
            cout<<Coefficient(r, i ) << "  ";     /// pascal coefficient

        cout << endl;
    }

    return 0;
}
