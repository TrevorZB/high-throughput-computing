#ifndef BLOCK_HEADER_H
#define BLOCK_HEADER_H

#include <string>
#include <vector>

struct BlockHeader
{
    unsigned int version;
    unsigned char hash_prev_block[32];
    unsigned char hash_merkle_root[32];
    unsigned int time;
    unsigned int bits;
    unsigned int nonce;
};

void init_block_header(
    BlockHeader &block_header,
    unsigned int version,
    std::string hash_prev_block_str,
    std::string hash_merkle_root_str,
    std::string time_stamp,
    unsigned int bits,
    unsigned int nonce);

#endif
