#include "CN.hpp"
#include <tuple>

//===============================================
//      CLASS
//===============================================

/**
 *  @brief Constutor padrao
 * */
CN::CN()
{
    row = 0;
    col = 0;

    mtx = nullptr;
}

/**
 *  @brief Construtor sobrecarregado para
 *         criacao de uma matriz nula
 *
 *  @param row -> linhas da matriz
 *  @param col -> colunas da matriz
 * */
CN::CN(unsigned row, unsigned col) 
{
    this->row = row;
    this->col = col;

    allocate(this->row, this->col);
}

/**
 *  @brief Construtor sobrecarregado de copia
 * */
CN::CN(const CN &c)
{
    allocate(c.row, c.col);
        
    this->row = c.row;
    this->col = c.col;

    for(i=0; i<row; ++i)
        for(j=0; j<col; ++j)
            this->mtx[i][j] = c.mtx[i][j];
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
 *  @brief Transforma a matriz em uma 
 *         matriz identidade
 * */
void CN::eye()
{
    if (row == col)
    {
        for(i=0; i<row; ++i)
            for(j=0; j<col; ++j)
            {
                if (i == j)
                    mtx[i][j] = 1;
                else
                    mtx[i][j] = 0;
            }
    }
}

/**
 *  @brief Overload da criacao de uma matriz
 *         identidade com nova quantidade
 *         de linhas e colunas
 * */
void CN::eye(unsigned new_row, unsigned new_col)
{
    if (row == col)
    {
        row = new_row;
        col = new_col; 
    
        allocate(row, col);

        for(i=0; i<row; ++i)
            for(j=0; j<col; ++j)
            {
                if (i == j)
                    mtx[i][j] = 1;
                else
                    mtx[i][j] = 0;
            }
    }
}

/**
 *  @brief realiza a transposicao da matriz
 * */
void CN::transpose()
{

    for(i=0; i<row; ++i)
        for(j=0; j<col; ++j)
            mtx[i][j] = mtx[j][i];
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
 *  @brief Verifica se as duas matrizes sao iguais
 *         comparando c1 (a que voce quer verificar) 
 *         com c2
 *
 *  @return true -> Caso sejam iguais
 *          false -> Caso contario
 * */
bool CN::equal(const CN &c)
{
    if (row == c.row)
    {
        if (col == c.col)
        {
            for(i=0; i<c.row; ++i)
                for(j=0; j<c.col; ++j)
                {
                    if(mtx[i][j] != c.mtx[i][j])
                        return false;
                }
        }
        else
          return false;
    }
    else
        return false;

    return true;
}

/**
 *  @brief Aloca/Realoca o novo tamanho da matriz
 *
 *  @param row -> quantidade de linhas
 *  @param col -> quantidade de colunas
 * */
void CN::allocate(unsigned new_row, unsigned new_col)
{
    row = new_row;
    col = new_col;

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

/**
 *  @brief Sobrecarga do operator de atribuicao (=)
 * */
void CN::operator=(const CN &c)
{
    if (!this->equal(c))
    {
            row = c.row;
            col = c.col;

            for(i=0; i<row; ++i)
                for(j=0; j<col; ++j)
                    this->mtx[i][j] = c.mtx[i][j];
    }

}

/**
 *  @brief Sobrecarga do operator de igualdade (==)
 *
 *  @return true -> Caso sejam iguais
 *          false -> Caso contrario
 * */
bool CN::operator==(const CN &c)
{
    if (this->equal(c))
        return true;

    else
        return false;
}

/**
 *  @brief Sobrecarga do operator de soma (+)
 *
 *  @return o resultado
 * */
CN CN::operator+(const CN &c)
{
    CN prov;

    if (this->row == c.row)
    {
        if (this->col == c.col)
        {   
            prov.allocate(this->row, this->col);

            for(i=0; i<row; ++i)
                for(j=0; j<col; ++j)
                    prov.mtx[i][j] = this->mtx[i][j]  + c.mtx[i][j];  

        }
    }

    return prov;
}


/**
 *  @brief Sobrecarga do operator de soma (-)
 *
 *  @return resultado
 * */
CN CN::operator-(const CN &c)
{
    CN prov;

    if (this->row == c.row)
    {
        if (this->col == c.col)
        {   
            prov.allocate(this->row, this->col);

            for(i=0; i<row; ++i)
                for(j=0; j<col; ++j)
                    prov.mtx[i][j] = this->mtx[i][j]  - c.mtx[i][j];  

        }
    }

    return prov;
}


/**
 *  @brief Sobrecarga do operator de multiplicacao (*)
 *
 *  @return resultado
 * */
CN CN::operator*(const CN &c)
{
    CN prov;

    if (col == c.row)
    {
        prov.allocate(row, c.col);
        for (i=0; i<row; ++i)
        {
            for(j=0; j<col; ++j)
            {
                for(k=0; k<col; ++k)
                {
                    prov.mtx[i][j] = this->mtx[i][k] * c.mtx[k][j];    
                }
            }
        }
    }

    return prov;

}
