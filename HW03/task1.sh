#!/usr/bin/env bash

#SBATCH -p wacc

#SBATCH --job-name=Task1

#SBATCH --output=Task1.out

#SBATCH --error=Task1.err

#SBATCH --time=0-00:01:00

#SBATCH --gres=gpu:1

./task1
