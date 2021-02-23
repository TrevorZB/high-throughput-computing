#!/usr/bin/env bash

#SBATCH -p wacc

#SBATCH --job-name=task1

#SBATCH --output=task1.out

#SBATCH --error=task1.err

#SBATCH --gres=gpu:1

./task2 10 1 4