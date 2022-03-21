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

    x.set(0, 0, 333.);
    cout << x;

    x.allocate(4,4);
    cout << x;
    x.set(3,3, 55);
    cout << "r1 c1: " << x.size_rows() << ' ' << x.size_cols() << endl;


    x.resize(3,3);
    cout << x;
    cout << "r2 c2: " << x.size_rows() << ' ' << x.size_cols() << endl;

    return 0;
}
