#include "block_header.h"
#include "helpers.h"
#include <algorithm>


void init_block_header(
    BlockHeader &block_header,
    unsigned int version,
    std::string hash_prev_block_str,
    std::string hash_merkle_root_str,
    std::string time_stamp,
    unsigned int bits,
    unsigned int nonce)
{
    add_spaces_to_hex_str(hash_prev_block_str);
    add_spaces_to_hex_str(hash_merkle_root_str);

    std::vector<unsigned char> hash_prev_block = hex_string_to_bytes(hash_prev_block_str);
    std::vector<unsigned char> hash_merkle_root = hex_string_to_bytes(hash_merkle_root_str);

    std::reverse(hash_prev_block.begin(), hash_prev_block.end());
    std::reverse(hash_merkle_root.begin(), hash_merkle_root.end());

    unsigned int time = get_time(time_stamp);
    
    block_header.version = version;

    std::copy(hash_prev_block.begin(), hash_prev_block.end(), block_header.hash_prev_block);
    std::copy(hash_merkle_root.begin(), hash_merkle_root.end(), block_header.hash_merkle_root);

    block_header.time = time;
    block_header.bits = bits;
    block_header.nonce = nonce;
}
