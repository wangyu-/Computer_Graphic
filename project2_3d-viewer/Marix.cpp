#include "Matrix.h"

Matrix::Matrix(const Matrix& m_)
    :diagonal(m_.getDiagonal()), P(m_.getP()){}

Matrix::Matrix(const std::vector<std::vector<double> > &dia_, const std::vector<std::vector<double> >&p_)
    :diagonal(dia_),P(p_)
{
}

Matrix::~Matrix()
{}

std::vector<std::vector<double> > Matrix::dotProduct(const std::vector<std::vector<double> >& a, const std::vector<std::vector<double> >& b){

    if(a[0].size() != b.size()){
        std::cout<<"The column of first matrix unequal to the row of second matrix!!"<<std::endl;
    }
    std::vector<std::vector<double> > c(a.size(), std::vector<double>(b[0].size(),0));
    int a_row = a.size();
    int a_col = a[0].size();
    int b_col = b[0].size();
    for (int i = 0; i < a_row; i++)
    {
        for (int j = 0; j < b_col; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k <a_col; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
            
        }
        
    }
    return c;
}

std::vector<std::vector<double> > Matrix::dotProduct(){

    if(diagonal[0].size() != P.size()){
        std::cout<<"The column of first matrix unequal to the row of second matrix!!"<<std::endl;
    }
    std::vector<std::vector<double> > c(diagonal.size(), std::vector<double>(P[0].size(),0));
    int a_row = diagonal.size();
    int a_col = diagonal[0].size();
    int b_col = P[0].size();
    for (int i = 0; i < a_row; i++)
    {
        for (int j = 0; j < b_col; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k <a_col; k++)
            {
                c[i][j] += diagonal[i][k] * P[k][j];
            }
            
        }
        
    }
    return c;
}

std::vector<std::vector<double> > Transpose(const std::vector<std::vector<double> >& matrix){

    std::vector<std::vector<double> > transpose(matrix[0].size(), std::vector<double>());
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            transpose[j].push_back(matrix[i][j]);
        }
    }
    
    return transpose;
}
