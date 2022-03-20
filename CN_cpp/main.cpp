#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "CN.hpp"

using namespace std;

int main()
{
    cout << "r | c: ";
    unsigned r,c;
    cin >> r >> c;
    
    CN x(r,c);

    cout << x;

    std::tie(r,c) = x.size();
    cout << r << '\t' << c << "\n\n";

    x.fill(3.1415);
    cout << x;

    return 0;
}
