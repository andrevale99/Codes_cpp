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
    friend void transpose(CN &C);
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
        void assign(const unsigned new_row_mem, const unsigned new_col_mem);

        std::tuple<unsigned, unsigned> size();
        unsigned size_rows();
        unsigned size_cols();
        unsigned int bytes_allocated();


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
        void allocate(unsigned new_row, unsigned new_col);
        void deallocate();

        double *mtx;

        unsigned row;
        unsigned col;

        unsigned row_mem; //Tamanho da memoria
        unsigned col_mem; //Tamanho da memoria

        string out_of_range = "[CN] Fora do tamanho da matriz\n";
        string erro_desconhecido = "[CN] Algum erro nao identificado\n";
        string erro_gravacao_arq = "[CN] Erro ao criar o arquivo\n";
        string erro_de_gravacao_RowCol = "[CN] Erro ao gravar a qtd de linas e colunas\n";
        string erro_de_gravacao_data = "[CN] Erro ao gravar os dados\n";
};

#endif
