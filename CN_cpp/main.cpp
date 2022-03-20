#include <ios>
#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "CN.hpp"

using namespace std;

int main()
{
    cout.setf(cout.boolalpha);

    cout << "r | c: ";
    unsigned r,c;
    cin >> r >> c;

    CN x(r,c);
    CN y(r,c);
    
    x.fill(2.);
    y.fill(3.21);
    
    cout << "X:\n" << x;
    cout << "Y:\n" << y;

    cout << x*y;
    

    return 0;
}
