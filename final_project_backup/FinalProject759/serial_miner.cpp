#include "mine.h"

bool serial_miner(BlockHeader &block_header, const std::string &target, int n)
{
    bool solved = false;
    for (int i = 0; i < n; i++)
    {
        if (mine(block_header, target)) 
        {
            solved = true;
        }
        else
        {
            block_header.nonce++;
        }
    }
    return solved;
}
