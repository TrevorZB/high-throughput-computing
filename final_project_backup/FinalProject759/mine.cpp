#include "mine.h"
#include "picosha2.h"
#include "helpers.h"


bool mine(BlockHeader &block_header, const std::string &target)
{
    unsigned char *byte_array = (unsigned char*)&block_header;
    std::vector<unsigned char> byte_array_vec(byte_array, byte_array + 80);

    std::string block_header_hex_str;
    picosha2::hash256_hex_string(byte_array_vec, block_header_hex_str);

    add_spaces_to_hex_str(block_header_hex_str);
    std::vector<unsigned char> second_hash_str_vec = hex_string_to_bytes(block_header_hex_str);

    std::string final_hash;
    picosha2::hash256_hex_string(second_hash_str_vec, final_hash);
    reverse_hex_string(final_hash);
    
    return final_hash < target;
}
