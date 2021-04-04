#include "block_header.h"
#include "helpers.h"
#include "picosha2.h"

int main(int argc, char *argv[])
{
    unsigned int version = 1;
    std::string hash_prev_block_str("0000000000000000000000000000000000000000000000000000000000000000");
    std::string hash_merkle_root_str("4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b");
    std::string time_stamp("2009-01-03 12:15:05");
    unsigned int bits = 486604799;
    unsigned int nonce = 2083236893;

    BlockHeader block_header;
    init_block_header(block_header, version, hash_prev_block_str, hash_merkle_root_str, time_stamp, bits, nonce);

    unsigned char *byte_array = (unsigned char*)&block_header;
    std::vector<unsigned char> byte_array_vec(byte_array, byte_array + 80);

    std::string block_header_hex_str;
    picosha2::hash256_hex_string(byte_array_vec, block_header_hex_str);

    add_spaces_to_hex_str(block_header_hex_str);
    std::vector<unsigned char> second_hash_str_vec = hex_string_to_bytes(block_header_hex_str);

    std::string second_str;
    picosha2::hash256_hex_string(second_hash_str_vec, second_str);

}