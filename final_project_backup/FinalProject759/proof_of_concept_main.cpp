#include "block_header.h"
#include "helpers.h"
#include "picosha2.h"
#include <iostream>

int main(int argc, char *argv[])
{
    /*
    Proof of concept for the hashing process
    Hashes the blockheader of the very first bitcoin block on the blockchain (block 0)
    Can view the block at this blockchain viewer:
    https://btc.com/000000000019d6689c085ae165831e934ff763ae46a2a6c172b3f1b60a8ce26f
    For the actual mining process, most of this functionality will be in separate functions
    Commented and fleshed out the implementation for demonstration purposes
    */

    // header data of the block pulled from the blockchain explorer
    unsigned int version = 1;
    std::string hash_prev_block_str("0000000000000000000000000000000000000000000000000000000000000000");
    std::string hash_merkle_root_str("4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b");
    std::string time_stamp("2009-01-03 12:15:05");
    unsigned int bits = 0x1d00ffff;
    unsigned int nonce = 0x7c2bac1d;

    /*
    init the blockheader struct with correctly formatted data
    formatting includes placing spaces between pairs of hex digits, converting time_stamp to
    unix time, swapping from big endian to small endian, etc.
    */
    BlockHeader block_header;
    init_block_header(block_header, version, hash_prev_block_str, hash_merkle_root_str, time_stamp, bits, nonce);

    // interpret the blockheader struct as byte data, save into a vector
    unsigned char *byte_array = (unsigned char*)&block_header;
    std::vector<unsigned char> byte_array_vec(byte_array, byte_array + 80);

    /*
    hash the byte structure using open source sha256 algorithm
    sha256 implementation pulled from:
    https://github.com/okdshin/PicoSHA2
    saves the hash digest as a hexstring
    */
    std::string block_header_hex_str;
    picosha2::hash256_hex_string(byte_array_vec, block_header_hex_str);

    /*
    bitcoin standard hashes the block header twice:
    header -> bytes -> sha256 hash -> bytes -> second (final) sha256 hash
    */
    add_spaces_to_hex_str(block_header_hex_str);
    std::vector<unsigned char> second_hash_str_vec = hex_string_to_bytes(block_header_hex_str);

    // final hash stores the calculated hash of the first block in the bitcoin blockchain
    std::string final_hash;
    picosha2::hash256_hex_string(second_hash_str_vec, final_hash);

    /*
    test to see if the caclulated hash is equal to the actual hash found back in 2009
    (need to reverse the string since blockchain explorer shows hash as big endian)
    */
    reverse_hex_string(final_hash);
    std::string actual_hash("000000000019d6689c085ae165831e934ff763ae46a2a6c172b3f1b60a8ce26f");
    if (final_hash == actual_hash)
    {
        std::cout << "hash calculation is correct" << std::endl;
    }
    else
    {
        std::cout << "hash calculation is incorrect" << std::endl;
    }

    /*
    test to see if the calculation to determine if a block was successfully mined or
    not is working correctly. header stores 256 bit target in a compressed 32 bit
    format so some formatting and padding is needed to accurately compare it
    against the calculated final hash
    */
    std::string header_bits = uncompact_bits(block_header.bits);
    if (final_hash < header_bits)
    {
        std::cout << "successful mine calculation is correct" << std::endl;
    }
    else
    {
        std::cout << "successful mine calculation is incorrect" << std::endl;
    }
}