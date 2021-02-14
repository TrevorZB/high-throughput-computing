#!/usr/bin/env bash

#SBATCH -p wacc

#SBATCH --job-name=Task3

#SBATCH --output=Task3.out

#SBATCH --error=Task3.err

#SBATCH --gres=gpu:1

for (( i=10; i < 30; i=i+1 )); do
    val=2**i
    ./task3 $val
done
