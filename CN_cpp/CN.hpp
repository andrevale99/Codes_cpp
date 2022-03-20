#ifndef CN_H
#define CN_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <iomanip>
#include <ostream>
#include <tuple>
#include <cstdint>

using std::uint8_t;

class CN
{

    friend std::ostream &operator<<(std::ostream &out, const CN &c)
    {
        for(unsigned i=0; i<c.row; ++i)
        {
            out << '(' << std::setw(10);

            for(unsigned j=0; j<c.col; ++j)
                out << c.mtx[i][j] << std::setw(10);
            out << ")\n";
        }
        out << '\n';

        return out;
    }

    public:
        CN();
        explicit CN(unsigned row, unsigned col);
        CN(const CN &c);

        ~CN();

        void fill(double valor);
        void eye();
        void eye(unsigned new_row, unsigned new_col);
        void transpose();

        std::tuple<unsigned, unsigned> size();
        unsigned size_rows();
        unsigned size_cols();

        bool equal(const CN &c);

        void allocate(unsigned new_row, unsigned new_col);
        void deallocate(unsigned row, unsigned col);

        void operator=(const CN &c);
        bool operator==(const CN &c);
        CN operator+(const CN &c);
        CN operator-(const CN &c);
        CN operator*(const CN &c);

    private:
        double **mtx;

        unsigned row;
        unsigned col;
        
        unsigned i;
        unsigned j;
        unsigned k;


};

#endif
