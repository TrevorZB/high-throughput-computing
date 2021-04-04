#ifndef HELPERS_H
#define HELPERS_H

#include <vector>
#include <string>

std::vector<unsigned char> hex_string_to_bytes(std::string hex_string);
void add_spaces_to_hex_str(std::string &hex_str);

#endif