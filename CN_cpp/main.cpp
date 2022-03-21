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
    x.fill(3.32);

    CN y(x);
    cout << y;

    cout << y*x;
    cout << y+y;
    cout << y-y;

    return 0;
}
