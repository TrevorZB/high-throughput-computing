#!/usr/bin/env bash

#SBATCH -p wacc

#SBATCH --job-name=Task3

#SBATCH --output=Task3.out

#SBATCH --error=Task3.err

./task3
