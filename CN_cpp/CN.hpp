#ifndef CN_H
#define CN_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <iomanip>
#include <ostream>
#include <tuple>
#include <string>
#include <sstream>
#include <limits>

using std::string;

class CN
{

    friend std::ostream &operator<<(std::ostream &out, const CN &c)
    {
        for(unsigned i=0; i<c.row; ++i)
        {
            out << '(' << std::setw(10);

            for(unsigned j=0; j<c.col; ++j)
                out << c.mtx[i * c.col + j] << std::setw(10);
            out << ")\n";
        }
        out << '\n';

        return out;
    }

    friend void eye(CN &c);
    friend CN operator*(const double valor, const CN &c);

    public:
        CN();
        explicit CN(unsigned row, unsigned col);
        CN(const CN &c);

        ~CN();

        void fill(double valor);
        void eye();
        void eye(unsigned new_row, unsigned new_col);
        void transpose();

        bool set(const unsigned idx_r, const unsigned idx_c, const double valor);
        bool resize(const unsigned new_row, const unsigned new_col);

        std::tuple<unsigned, unsigned> size();
        unsigned size_rows();
        unsigned size_cols();

        void allocate(unsigned new_row, unsigned new_col);
        void deallocate(unsigned row, unsigned col);

        bool equal(const CN &c);

        void operator=(const CN &c);
        bool operator==(const CN &c);
        CN operator+(const CN &c);
        CN operator-(const CN &c);
        CN operator*(const CN &c);
        CN operator*(const double valor);

        double operator()(const unsigned idx_r, const unsigned idx_c);

        bool save(string name);
        bool read(string name);

        unsigned i;
        unsigned j;
        unsigned k;

    private:
        double *mtx;

        unsigned row;
        unsigned col;
};

#endif
