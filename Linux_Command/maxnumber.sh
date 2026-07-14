#!/bin/bash

echo "Enter 5 numbers separated by spaces:"
read -a numbers

echo "Numbers entered: ${numbers[@]}".

max=${numbers[0]}

for num in "${numbers[@]}"; do
    if (( num > max )); then
        max=$num
    fi
done

echo "The maximum number is: $max"