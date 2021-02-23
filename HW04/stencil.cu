// Computes the convolution of image and mask, storing the result in output.
// Each thread should compute _one_ element of output.
// Shared memory should be allocated _dynamically_ only.
//
// image is an array of length n.
// mask is an array of length (2 * R + 1).
// output is an array of length n.
//
// Assumptions:
// - 1D configuration
// - blockDim.x >= 2 * R + 1
//
// The following should be stored/computed in shared memory:
// - The entire mask
// - The elements of image needed to compute the elements of output corresponding to the threads in the given block
// - The output image elements corresponding to the given block before it is written back to global memory
__global__ void stencil_kernel(const float* image, const float* mask, float* output, unsigned int n, unsigned int R)
{
    extern __shared__ float s[];
    int block_x = blockIdx.x;
    int thread_x = threadIdx.x;
    int thread = threadIdx.x + blockDim.x * block_x;
    int s_mask_size = 2 * R + 1;
    int s_image_size = 2 * R + block_x;

    // shared memory broken into mask, image, and output arrays
    float *s_mask = &s[0];
    float *s_image = &s[s_mask_size];
    float *s_output = &s[s_mask_size + s_image_size];

    // threads with id lower than the mask size
    // bring over their mask index from global to shared memory
    if (thread_x < s_mask_size - 1)
    {
        s_mask[thread_x] = mask[thread_x];
    }

    // calculates how many shared memory image indexes
    // this thread must bring over from global memory
    int work = (2 * R) / block_x + 1;

    // brings over this thread's designated image indexes
    // from global memory to shared memory
    for (int i = 0; i < work; i++)
    {
        int s_i_index = thread_x * work + i;
        int i_index = // index of the image that is brought over
        if (s_i_index < s_image_size - 1)
        {
            s_image[i_index] = image[i_index]; // ????? s_image index is probably supposed to be different than image index??
        }
    }

    // wait for threads in this block to finish bringing
    // over the mask and image values
    __syncthreads();

    // calculate the convolution summation
    float out = 0.0;
    for (int j = -R; j <= R; j++)
    {
        int image_val;
        int s_i_index = thread_x + j; // MIGHT NEED TO FIX THIS? SHOULD USE THREAD.X ID TO INDEX SHARED MEMORY IMAGE SINCE WE ONLY BROUGHT A SLICE OF THE IMAGE OVER
        if (s_i_index < 0 || s_i_index > n - 1)
        {
            image_val = 1; // out of bounds, default value
        } else
        {
            image_val = s_image[s_i_index]; // grab from shared memory
        }
        out += image_val * s_mask[j + R];
    }
    s_output[thread_x] = out;

    // write shared memory output to global memory output
}

// Makes one call to stencil_kernel with threads_per_block threads per block.
// The kernel call should be followed by a call to cudaDeviceSynchronize for timing purposes.
//
// Assumptions:
// - threads_per_block >= 2 * R + 1
__host__ void stencil(const float* image,
                      const float* mask,
                      float* output,
                      unsigned int n,
                      unsigned int R,
                      unsigned int threads_per_block)
{
    int shared_mem = 4 * R + 2 * threads_per_block + 1;
    int blocks_per_grid = (n + threads_per_block - 1) / threads_per_block;
    stencil_kernel<<<blocks_per_grid, threads_per_block, sizeof(float) * shared_mem>>>(image, mask, output, n, R);
}