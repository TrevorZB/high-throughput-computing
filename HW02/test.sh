#!/bin/bash

for (( i=5; i <= 10; i=i+1 )); do
    val=$((2**i))
    echo "val: " + $val
    ./task1 $val
done