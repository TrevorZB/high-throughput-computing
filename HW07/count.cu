// #include <thrust/reduce.h>
// #include <thrust/functional.h>
// #include <iostream>
// #include <thrust/iterator/constant_iterator.h>

// int main()
// {
// const int N = 7;
// int A[N] = { 1, 4, 4, 4, 2, 2, 1 }; 
// int C[N];
// int D[N];

// thrust::pair<int*, int*> new_end;
// thrust::equal_to<int> binary_pred;
// thrust::plus<int> binary_op;
// new_end = thrust::reduce_by_key(A, A + N, thrust::make_constant_iterator(1), C, D, binary_pred, binary_op);

// for (int i = 0; i < new_end.first - C; i++) {
//     std::cout << C[i] << " - " << D[i] << "\n";
// }
// return 0;
// }

#include <thrust/sort.h>
#include <thrust/reduce.h>
#include <thrust/iterator/constant_iterator.h>

void count(const thrust::device_vector<int>& d_in,
                 thrust::device_vector<int>& values,
                 thrust::device_vector<int>& counts)
{
    thrust::sort(d_in.begin(), d_in.end()); // sort in ascending order

    thrust::pair<int*, int*> key_end_value_end; // stores end location of values and counts
    thrust::constant_iterator<int> ones(1); // reduce_by_key sums the values, so values of 1 will result in counts

    key_end_value_end = thrust::reduce_by_key(d_in.begin(), d_in.end(), ones, values, counts);
}