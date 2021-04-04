#ifndef SERIAL_MINER_H
#define SERIAL_MINER_H

#include "block_header.h"

bool serial_miner(BlockHeader &block_header, const std::string &target, int n);

#endif