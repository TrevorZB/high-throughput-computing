#!/usr/bin/env bash

#SBATCH -p wacc

#SBATCH --job-name=Plot

#SBATCH --output=Plot.out

#SBATCH --error=Plot.err

for (( i=10; i <= 30; i=i+1 )); do
    val=$((2**$i))
    ./task1 $val
done
