#include "matmul.h"
#include <iostream>
#include <stdlib.h>
#include <random>
#include <chrono>
#include <vector>

using std::chrono::high_resolution_clock;
using std::chrono::duration;

void time_test(const double* A, 
               const double* B, 
               const unsigned int n,
               void (*mmul_func)(
                   const double* A,
                   const double* B,
                   double* C,
                   const unsigned int n
               ))
{
    double *C = new double[n * n]();
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, std::milli> duration_sec;

    start = high_resolution_clock::now();
    (*mmul_func)(A, B, C, n);
    end = high_resolution_clock::now();
    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);

    std::cout << duration_sec.count() << "\n";
    std::cout << C[(n * n) - 1] << "\n";

    delete[] C;
}

int main()
{
    unsigned int n = 1024;

    double *A = new double[n * n]();
    double *B = new double[n * n]();

    std::default_random_engine gen{static_cast<long unsigned int>(time(0))};
    std::uniform_real_distribution<double> dist(1.0, 10.0);

    for (std::size_t i = 0; i < (n * n); i++)
    {
        A[i] = dist(gen);
    }
    for (std::size_t i = 0; i < (n * n); i++)
    {
        B[i] = dist(gen);
    }

    std::cout << n << "\n";
    time_test(A, B, n, mmul1);
    time_test(A, B, n, mmul2);
    time_test(A, B, n, mmul3);

    double *C = new double[n * n]();
    std::vector<double> A_vec(A, A + (n * n));
    std::vector<double> B_vec(B, B + (n * n));

    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, std::milli> duration_sec;

    start = high_resolution_clock::now();
    mmul4(A_vec, B_vec, C, n);
    end = high_resolution_clock::now();
    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);

    std::cout << duration_sec.count() << "\n";
    std::cout << C[(n * n) - 1] << "\n";

    delete[] C;
    delete[] A;
    delete[] B;
}