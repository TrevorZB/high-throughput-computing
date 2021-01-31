#!/usr/bin/env bash

#SBATCH -p wacc

#SBATCH --job-name=pwdsh

#SBATCH --output=pwdsh.out

#SBATCH --error=pwdsh.err

#SBATCH --time=0-00:01:00

echo $(pwd)
