#!/usr/bin/env bash

#SBATCH -p wacc

#SBATCH --job-name=test

#SBATCH --output=test.out

#SBATCH --error=test.err

val=$((2**5))
./test val