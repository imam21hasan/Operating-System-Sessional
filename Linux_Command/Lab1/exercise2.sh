#!/bin/bash

read -p "Enter two numbers : " num1 num2

if [ $num1 -gt $num2 ]; then
    echo "$num1 is greater than $num2"

elif [ $num1 -lt $num2 ]; then
    echo "$num1 is less than $num2"

else
    echo "$num1 and $num2 is equal"
fi

echo "Sum : $((num1 + num2)) , Difference : $((num1 - num2)) , Product : $((num1 * num2)) , Quotient : $((num1 / num2)) and Remember : $((num1 % num2))"

