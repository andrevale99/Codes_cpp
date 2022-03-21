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
    
    CN x(r, c);
    x.fill(122);
    cout << "\nX1:\n" << x << x.bytes_allocated() << endl;
    cout << x.size_rows() << '\t' << x.size_cols() << endl << endl;

    x.resize(r*2, c*2);
    cout << "\nX2:\n" << x << x.bytes_allocated() << endl;
    cout << x.size_rows() << '\t' << x.size_cols() << endl << endl;

    x.resize(r, c);
    cout << "\nX3:\n" << x << x.bytes_allocated() << endl;
    cout << x.size_rows() << '\t' << x.size_cols() << endl << endl;

    x.resize(r*2, c*2);
    cout << "\nX4:\n" << x << x.bytes_allocated() << endl;
    cout << x.size_rows() << '\t' << x.size_cols() << endl << endl;

    x.resize(r*3, c*3);
    cout << "\nX5:\n" << x << x.bytes_allocated() << endl;
    cout << x.size_rows() << '\t' << x.size_cols() << endl << endl;

    cout << x(7,7) << endl;
    
    return 0;
}
