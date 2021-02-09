#include "convolution.h"

void convolve(const float *image, float *output, std::size_t n, const float *mask, std::size_t m)
{
    std::size_t output_index, mask_index;
    int image_x_index, image_y_index, image_index;
    float image_pix, weight_pix, sum;
    bool cond_i, cond_j;
    for (std::size_t x = 0; x < n; x++)
    {
        for (std::size_t y = 0; y < n; y++)
        {
            sum = 0; 
            output_index = (x * n) + y;
            for (std::size_t i = 0; i < m; i++)
            {
                for (std::size_t j = 0; j < m; j++)
                {
                    mask_index = (i * m) + j;
                    image_x_index = x + i - ((m - 1) / 2);
                    image_y_index = y + j - ((m - 1) / 2);
                    cond_i = (image_x_index < 0 || image_x_index >= (int)n);
                    cond_j = (image_y_index < 0 || image_y_index >= (int)n);
                    if (cond_i && cond_j)
                    {
                        image_pix = 0.0;
                    } 
                    else if (cond_i || cond_j)
                    {
                        image_pix = 1.0;
                    }
                    else
                    {
                        image_index = (image_x_index * n) + image_y_index;
                        image_pix = image[image_index];
                    }
                    weight_pix = mask[mask_index];
                    sum += image_pix * weight_pix;
                }
            }
            output[output_index] = sum;
        }
    }
}
