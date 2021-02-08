#include "matmul.h"

// using for testing purposes
// #include <iostream>

void mmul1(const double* A, const double* B, double* C, const unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            for (unsigned int k = 0; k < n; k++)
            {
                C[(i * n) + j] += A[(i * n) + k] * B[(k * n) + j];
            }
        }
    }
}


void mmul2(const double* A, const double* B, double* C, const unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int k = 0; k < n; k++)
        {
            for (unsigned int j = 0; j < n; j++)
            {
                C[(i * n) + j] += A[(i * n) + k] * B[(k * n) + j];
            }
        }
    }
}


void mmul3(const double* A, const double* B, double* C, const unsigned int n)
{
    for (unsigned int j = 0; j < n; j++)
    {
        for (unsigned int k = 0; k < n; k++)
        {
            for (unsigned int i = 0; i < n; i++)
            {
                C[(i * n) + j] += A[(i * n) + k] * B[(k * n) + j];
            }
        }
    }
}



void mmul4(const std::vector<double>& A, const std::vector<double>& B, double* C, const unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            for (unsigned int k = 0; k < n; k++)
            {
                C[(i * n) + j] += A[(i * n) + k] * B[(k * n) + j];
            }
        }
    }
}

// int main()
// {
//     const double A[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
//     const double B[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
//     double C[9] = {};
//     mmul2(A, B, C, 3);
//     for (std::size_t i = 0; i < 9; i++)
//     {
//         std::cout << C[i] << ", ";
//     }
//     std::cout << std::endl;
// }
