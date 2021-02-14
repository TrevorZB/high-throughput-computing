#!/usr/bin/env bash

#SBATCH -p wacc

#SBATCH --job-name=Task2

#SBATCH --output=Task2.out

#SBATCH --error=Task2.err

#SBATCH --time=0-00:01:00

#SBATCH --gres=gpu:1

./task2
