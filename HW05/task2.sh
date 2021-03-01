#!/usr/bin/env bash

#SBATCH -p wacc

#SBATCH --job-name=task2

#SBATCH --output=task2.out

#SBATCH --error=task2.err

#SBATCH --gres=gpu:1

./task2 4 2