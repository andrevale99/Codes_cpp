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
    cout << x.bytes_allocated() << endl;

    x.resize(r*2, c*2);
    cout << x;
    cout << x.bytes_allocated() << endl;

    x.resize(r/2, c/2);
    cout << x;
    cout << x.bytes_allocated() << endl;

    return 0;
}
