#!/usr/bin/env bash

#SBATCH -p wacc

#SBATCH --job-name=task1

#SBATCH --output=task1.out

#SBATCH --error=task1.err

#SBATCH --gres=gpu:1

for (( i=5; i < 15; i=i+1 )); do
    val=$((2**$i))
    ./task1 $val 1024
done