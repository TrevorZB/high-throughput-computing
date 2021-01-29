#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    for (int i = 0; i <= N; i++)
    {
        i == 6 ? printf("%d\n", i) : printf("%d ", i);
    }
    for (int i = N; i >= 0; i--)
    {
        std::cout << i << (i == 0 ? "\n" : " ");
    }
}