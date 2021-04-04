#include "helpers.h"
#include <sstream>

std::vector<unsigned char> hex_string_to_bytes(std::string hex_string)
{
    std::istringstream stream(hex_string);
    std::vector<unsigned char> bytes;

    unsigned int byte;
    while (stream >> std::hex >> byte)
    {
        bytes.push_back(byte);
    }

    return bytes;
}

void add_spaces_to_hex_str(std::string &hex_str)
{
    int orig_size = hex_str.size();
    for (int i = 1; i <= orig_size / 2 - 1; i++)
    {
        hex_str.insert(i * 2 + (i - 1), " ");
    }
}
