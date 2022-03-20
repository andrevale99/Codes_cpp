#ifndef CN_H
#define CN_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <iomanip>
#include <ostream>
#include <tuple>

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
        return out;
    }

    public:
        CN();
        CN(unsigned row, unsigned col);

        ~CN();

        void fill(double valor);

        std::tuple<unsigned, unsigned> size();
        unsigned size_rows();
        unsigned size_cols();

        void allocate(unsigned row, unsigned col);
        void deallocate(unsigned row, unsigned col);

    private:
        double **mtx;

        unsigned row;
        unsigned col;
        
        unsigned i;
        unsigned j;


};

#endif
