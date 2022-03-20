#include "CN.hpp"

/**
 *  @brief Constutor padrao
 * */
CN::CN() {}

/**
 *  @brief COnstrutor sobrecarregado
 *
 *  @param row -> linhas da matriz
 *  @param col -> colunas da matriz
 * */
CN::CN(unsigned row, unsigned col) 
    : row(row),
      col(col)
{

    allocate(this->row, this->col);
}

/**
 *  @brief Destrutor padrao, desaloca a memoria
 *         da matriz
 * */
CN::~CN()
{
    deallocate(row, col);
}

/**
 *  @brief Preenche a matriz com algum valor
 * */
void CN::fill(double valor)
{
    for(i=0; i<row; ++i)
        for(j=0; j<col; ++j)
            mtx[i][j] = valor;
}

/**
 *  @brief Retorna o tamanho da matriz
 *         Lembrando que para receber o tamanho
 *         deve utilizar "std::tie(var1, var2) = obj.size()"
 *         na main.
 * */
std::tuple<unsigned, unsigned> CN::size()
{
    return {row, col};
}

/**
 * @brief Retorna a quantidade de linhas
 * */
unsigned CN::size_rows()
{
    return row;
}

/**
 * @brief Retorna a quantidade de colunas
 * */
unsigned CN::size_cols()
{
    return col;
}

/**
 *  @brief Aloca/Realoca o novo tamanho da matriz
 *
 *  @param row -> quantidade de linhas
 *  @param col -> quantidade de colunas
 * */
void CN::allocate(unsigned row, unsigned col)
{
    mtx = new double*[row];
    for(i=0; i<row; ++i)
        mtx[i] = new double[col];
}

/**
 *  @brief desaloca a memoria utilizada pela matriz
 * */
void CN::deallocate(unsigned row, unsigned col)
{
    for(i=0; i<row; ++i)
       delete[] mtx[i];

    delete[] mtx;
}

