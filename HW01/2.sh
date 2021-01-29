#!/bin/bash

cd somedir

cat sometext.txt

tail -n 5 sometext.txt

tail -n 5 *.txt

for (( i=0; i <= 6; i=i+1 )); do
    echo $i
done
