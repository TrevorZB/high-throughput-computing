#include "block_header.h"
#include "helpers.h"
#include "picosha2.h"
#include "serial_miner.h"
#include <iostream>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration;

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    bool solved = false;

    unsigned int version = 0x20000000;
    std::string hash_prev_block_str("0000000000000000007962066dcd6675830883516bcf40047d42740a85eb2919");
    std::string hash_merkle_root_str("31951c69428a95a46b517ffb0de12fec1bd0b2392aec07b64573e03ded31621f");
    std::string time_stamp("2017-12-18 12:35:25");
    unsigned int bits = 0x18009645;
    unsigned int nonce = 0x1;

    BlockHeader block_header;
    init_block_header(block_header, version, hash_prev_block_str, hash_merkle_root_str, time_stamp, bits, nonce);
    const std::string target = uncompact_bits(block_header.bits);

    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, std::milli> duration_sec;

    start = high_resolution_clock::now();
    solved = serial_miner(block_header, target, n);
    end = high_resolution_clock::now();

    duration_sec = std::chrono::duration_cast<duration<double, std::milli>>(end - start);

    std::cout << solved << std::endl;
    std::cout << duration_sec.count() << std::endl;
}