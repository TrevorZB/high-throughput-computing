// implements the 'first add during global load' version (Kernel 4) for the parallel reduction
// g_idata is the array to be reduced, and is available on the device.
// g_odata is the array that the reduced results will be written to, and is available on the device.
// expects a 1D configuration.
// uses only dynamically allocated shared memory.
__global__ void reduce_kernel(float* g_idata, float* g_odata, unsigned int n)
{
    extern __shared__ float s[];
    int bid = blockIdx.x;
    int threads_per_block = blockDim.x;
    int tid = threadIdx.x;
    int thread = tid + threads_per_block * bid;

    // shared memory as input pointer
    float *s_input = &s[0];

    int g_input_index = tid + threads_per_block * bid * 2; // global input index
    int sec_g_input_index = g_input_index + threads_per_block; // second global input index

    // only pull into shared memory if within bounds of the inputted array
    if (g_input_index < N & sec_g_input_index < N)
    {
        s_input[thread] = g_odata[g_input_index] + g_odata[g_input_index + threads_per_block];
    } elif (g_input_index < N)
    {
        s_input[thread] = g_odata[g_input_index]
    }

    // wait for all threads to finish bringing in data
    __syncthreads();

    // sum the elements in the shared memory input array
    // might need boundary conditionals here
    for (int i = threads_per_block / 2; i > 0; i /= 2)
    {
        if (tid < i)
        {
            s_input[tid] += s_input[i + tid];
        }
        __syncthreads(); // since doing in place, have to wait for each round of threads to finish
    }

    // write shared summation to global output array
    if (thread == 0)
    {
        g_odata[bid] = s_input[0];
    }
}

// the sum of all elements in the *input array should be written to the first element of the *input array.
// calls reduce_kernel repeatedly if needed. _No part_ of the sum should be computed on host.
// *input is an array of length N in device memory.
// *output is an array of length = (number of blocks needed for the first call of the reduce_kernel) in device memory.
// configures the kernel calls using threads_per_block threads per block.
// the function should end in a call to cudaDeviceSynchronize for timing purposes
__host__ void reduce(float** input, float** output, unsigned int N, unsigned int threads_per_block)
{
    int blocks_per_grid;
    int *orig_in = *input;
    int *temp;

    blocks_per_grid = N; // do this so first iteration of the loop is correct

    // iterates until the last run only used 1 block, means we are done
    while (blocks_per_grid != 1)
    {
        N = blocks_per_grid; // new size of input
        blocks_per_grid = N / (threads_per_block * 2); // new number of blocks needed

        // flip input and output pointers
        temp = *input;
        input = output;
        output = &temp;

        // call kernel with new values
        reduce_kernel<<<blocks_per_grid, threads_per_block, sizeof(float) * threads_per_block>>>(*input, *output, N);
    }
    // write final summation to first element of input array
    *orig_in[0] = *output[0];
}