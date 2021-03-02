#include "matmul.h"
#include <iostream>
#include <stdlib.h>
#include <random>
#include <chrono>
#include <vector>

using std::chrono::high_resolution_clock;
using std::chrono::duration;

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    std::cout << N << "\n";

    double *A = new double[N * N]();
    double *B = new double[N * N]();

    // randomize the seed, create distribution
    std::default_random_engine gen{static_cast<long unsigned int>(time(0))};
    std::uniform_real_distribution<double> dist(1.0, 10.0);

    // initialize arrays with random doubles between 1.0 and 10.0
    for (std::size_t i = 0; i < (N * N); i++)
    {
        A[i] = dist(gen);
    }
    for (std::size_t i = 0; i < (N * N); i++)
    {
        B[i] = dist(gen);
    }

    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, std::milli> duration_sec;
    double *c;

    c = new double[N * N]();

    start = high_resolution_clock::now();
    mmul1(A, B, c, N);
    end = high_resolution_clock::now();
    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);

    std::cout << duration_sec.count() << "\n";
    delete[] c;
    delete[] A;
    delete[] B;
}




