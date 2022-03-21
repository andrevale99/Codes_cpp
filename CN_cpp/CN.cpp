#include "CN.hpp"
#include <fstream>
#include <tuple>


//===============================================
//      FRIENDS
//===============================================
CN operator*(const double valor, const CN &c)
{
    CN prov(c.row, c.col);
    
       
    for (unsigned i=0; i<prov.row; ++i)
        for (unsigned j=0; j<prov.col; ++j)
            prov.mtx[i * c.col + j] = c.mtx[i * prov.col + j] * valor;    

    return prov;
}

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

    for (i=0; i<row; ++i)
        for (j=0; j<col; ++j)
            this->mtx[i *col + j] = c.mtx[i * col + j];
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
    for (i=0; i<row; ++i)
        for (j=0; j<col; ++j)
            mtx[i * col + j] = valor;
}

/**
 *  @brief Transforma a matriz em uma 
 *         matriz identidade
 * */
void CN::eye()
{
    if (row == col)
    {
        for (i=0; i<row; ++i)
            for (j=0; j<col; ++j)
            {
                if (i == j)
                    mtx[i * col + j] = 1;
                else
                    mtx[i * col + j] = 0;
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

        for (i=0; i<row; ++i)
            for (j=0; j<col; ++j)
            {
                if (i == j)
                    mtx[i * col + j] = 1;
                else
                    mtx[i * col + j] = 0;
            }
    }
}

/**
 *  @brief realiza a transposicao da matriz
 * */
void CN::transpose()
{

    for (i=0; i<row; ++i)
        for (j=0; j<col; ++j)
            mtx[i * col + j] = mtx[j * col + i];
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
            for (i=0; i<c.row; ++i)
                for (j=0; j<c.col; ++j)
                {
                    if (mtx[i * col + j] != c.mtx[i * col + j])
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

    mtx = new double[row * col];
}

/**
 *  @brief desaloca a memoria utilizada pela matriz
 * */
void CN::deallocate(unsigned row, unsigned col)
{
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
                    this->mtx[i * col + j] = c.mtx[i * col + j];
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
 *         entre matrizes
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

            for (i=0; i<row; ++i)
                for (j=0; j<col; ++j)
                    prov.mtx[i * col + j] = this->mtx[i *col + j]  + c.mtx[i * col + j];  

        }
    }

    return prov;
}


/**
 *  @brief Sobrecarga do operator de soma (-)
 *         entre matrizes
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

            for (i=0; i<row; ++i)
                for (j=0; j<col; ++j)
                    prov.mtx[i * col + j] = this->mtx[i * col + j]  - c.mtx[i * col + j];  

        }
    }

    return prov;
}


/**
 *  @brief Sobrecarga do operator de multiplicacao (*)
 *         entre matrizes
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
            for (j=0; j<col; ++j)
            {
                for (k=0; k<col; ++k)
                {
                    prov.mtx[i * col + j] = this->mtx[i * col + k] * c.mtx[k * col + j];    
                }
            }
        }
    }

    return prov;
}


/**
 *  @brief Sobrecarga do operator de multiplicacao (*)
 *         entre uma matriz e uma constante
 *
 *  @return resultado
 * */
CN CN::operator*(const double valor)
{
    CN prov;

    prov.allocate(row, col);
    
    for (i=0; i<row; ++i)
        for (j=0; j<col; ++j)
            prov.mtx[i * col + j] = this->mtx[i * col + j] * valor;    

    return prov;
}

/**
 * @brief Salva a matriz em um arquivo
 *
 * @return true -> Caso o arquivo foi escrito corretamente
 *         false -> Caso contrario, nao salva
 * */
bool CN::save(string name)
{
    std::ofstream arq(name, std::ios::out);

    if (arq.good())
    {
        arq << row << ' ' << col << "\n\n";
        
        if (arq.fail())
        {
            arq.close();
            return false;
        }

        for (i=0; i<row; ++i)
        {
            for (j=0; j<col; ++j)
            {
                arq << mtx[i * col + j] << ' ';
                
                if (arq.fail())
                {
                    arq.close();
                    return false;
                }
            }//FIM do col for
            
            arq << '\n';
        
        }//FIM do row for
    }//FIM arq.good()

    else
        return false;

    arq.close();

    return true;
}

/**
 * @brief Ler um arquivo que contem uma matriz
 *
 * @return true -> Caso o arquivo foi lido corretamente
 *         false -> Caso contrario, e a matriz torna uma nula
 *                  com tamanho 2x2
 *
 *  AINDA PRECISA SER FEITO
 * */
bool CN::read(string name)
{
    std::ifstream arq(name, std::ios::in);
    
    if (arq.is_open())
    {

    }

    else
        return false;
    
    arq.close();

    return true;
}
