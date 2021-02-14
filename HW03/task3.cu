#include <cuda.h>
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include "vscale.cuh"

void randomize_array(float *a, int size, float start, float stop)
{
    // randomize the seed, create distribution
    std::default_random_engine gen{static_cast<long unsigned int>(time(0))};
    std::uniform_real_distribution<float> dist(start, stop);

    for (int i = 0; i < size; i++)
    {
        a[i] = dist(gen);
    }
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int threads_per_block = 512;
    int blocks = n / threads_per_block + 1;

    float *a_host = new float[n];
    float *a_dev;
    float *b_host = new float[n];
    float *b_dev;


    cudaMalloc((void **)&a_dev, sizeof(float) * n);
    randomize_array(a_host, n, -10.0, 10.0);
    cudaMemcpy(a_dev, a_host, sizeof(float) * n, cudaMemcpyHostToDevice);
    
    cudaMalloc((void **)&b_dev, sizeof(float) * n);
    randomize_array(b_host, n, 0.0, 1.0);
    cudaMemcpy(b_dev, b_host, sizeof(float) * n, cudaMemcpyHostToDevice);

    cudaEvent_t start;
    cudaEvent_t stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    cudaEventRecord(start);
    vscale<<<blocks, threads_per_block>>>(a_dev, b_dev, n);
    cudaEventRecord(stop);
    cudaEventSynchronize(stop);

    float ms;
    cudaEventElapsedTime(&ms, start, stop);

    cudaMemcpy(b_host, b_dev, sizeof(float) * n, cudaMemcpyDeviceToHost);

    printf("%f\n", ms);
    printf("%f\n", b_host[0]);
    printf("%f\n", b_host[n - 1]);

    delete[] a_host;
    delete[] b_host;
    cudaFree(a_dev);
    cudaFree(b_dev);
}