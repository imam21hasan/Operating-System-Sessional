#!/bin/bash

# Check Even or Odd Number
read -p "Enter a number: " num

if [ $((num % 2)) -eq 0 ]; then
    echo "Even"
else
    echo "Odd"
fi



# Check Positive, Negative or Zero

read -p "Enter a number: " num

if [ $num -gt 0 ]; then
    echo "Positive"
elif [ $num -lt 0 ]; then
    echo "Negative"
else
    echo "Zero"
fi



# Largest of Three Numbers
read -p "Enter three numbers: " a b c

if [ $a -gt $b ] && [ $a -gt $c ]; then
    echo "$a is the largest"
elif [ $b -gt $a ] && [ $b -gt $c ]; then
    echo "$b is the largest"
else
    echo "$c is the largest"
fi



# Check Leap Year
read -p "Enter a year: " year

if [ $((year % 4)) -eq 0 ] && [ $((year % 100)) -ne 0 ] || [ $((year % 400)) -eq 0 ]; then
    echo "$year is a leap year"
else
    echo "$year is not a leap year"
fi



# Check Vowel or Consonant
read -p "Enter a character: " char

case $char in
a | e | i | o | u | A | E | I | O | U)
    echo "$char is a vowel"
    ;;
*)
    echo "$char is a consonant"
    ;;
esac



# Calculator using Case
read -p "Enter two numbers: " a b
read -p "Enter an operator (+, -, *, /): " operator

case $operator in
+)
    echo "Answer = $((a + b))"
    ;;
-)
    echo "Answer = $((a - b))"
    ;;
\*)
    echo "Answer = $((a * b))"
    ;;
/)
    if [ $b -ne 0 ]; then
        echo "Answer = $((a / b))"
    else
        echo "Division by zero is not allowed"
    fi
    ;;
*)
    echo "Invalid Operator"
    ;;
esac



# Print 1 to n
read -p "Enter a number: " n
for ((i = 1; i <= n; i++)); do
    echo "$i"
done



# Sum of n natural numbers
read -p "Enter a number: " n
sum=0
for ((i = 1; i <= n; i++)); do
    sum=$((sum + i))
done
echo "Sum = $sum"



# Factorial of a number
read -p "Enter a number: " n
fact=1
for ((i = 1; i <= n; i++)); do
    fact=$((fact * i))
done
echo "Factorial = $fact"



# Multiplication Table
read -p "Enter a number: " n
for ((i = 1; i <= 10; i++)); do
    echo "$n x $i = $((n * i))"
done



# Reverse a number
read -p "Enter a number: " n
rev=0
while [ $n -gt 0 ]; do
    digit=$((n % 10))
    rev=$((rev * 10 + digit))
    n=$((n / 10))
done
echo "Reverse = $rev"



# Palindrome Number
read -p "Enter a number: " n
temp=$n
rev=0
while [ $temp -gt 0 ]; do
    digit=$((temp % 10))
    rev=$((rev * 10 + digit))
    temp=$((temp / 10))
done

if [ $n -eq $rev ]; then
    echo "$n is a palindrome"
else
    echo "$n is not a palindrome"
fi



# Prime Number
read -p "Enter a number: " n

if [ $n -le 1 ]; then
    echo "$n is not a prime number"
else
    for ((i = 2; i <= n; i++)); do
        if [ $((n % i)) -eq 0 ]; then
            echo "$n is not a prime number"
            exit
        fi
    done
    echo "$n is a prime number"
fi



# Prime Numbers Between Two Numbers
read -p "Enter two numbers: " a b
for ((i = a; i <= b; i++)); do
    if [ $i -le 1 ]; then
        continue
    fi
    for ((j = 2; j <= i; j++)); do
        if [ $((i % j)) -eq 0 ]; then
            break
        fi
    done
    if [ $j -eq $i ]; then
        echo "$i"
    fi
done



# Display Array Elements
read -p "Enter number of elements: " n
declare -a arr
for ((i = 0; i < n; i++)); do
    read -p "Enter element $((i + 1)): " arr[i]
done
echo "Array elements: ${arr[@]}"

arr=(10 20 30 40 50)
echo "Array elements: ${arr[@]}"

arr=(10 20 30 40 50)
for i in "${arr[@]}"; do
    echo "$i"
done



# Sum of Array Elements
arr=(10 20 30 40 50)
sum=0
for i in "${arr[@]}"; do
    sum=$((sum + i))
done
echo "Sum of array elements: $sum"



# Maximum and Minimum in an Array
arr=(10 20 30 40 50)
max=${arr[0]}
min=${arr[0]}
for i in "${arr[@]}"; do
    if [ $i -gt $max ]; then
        max=$i
    fi
    if [ $i -lt $min ]; then
        min=$i
    fi
done
echo "Maximum: $max"
echo "Minimum: $min"



# Search an Element in an Array
arr=(10 20 30 40 50)
read -p "Enter an element to search: " element
found=0
for i in "${arr[@]}"; do
    if [ $i -eq $element ]; then
        found=1
        break
    fi
done
if [ $found -eq 1 ]; then
    echo "Element found in the array"
else
    echo "Element not found in the array"
fi



# Sort an Array (Ascending or Descending)
arr=(50 20 40 10 30)

# Ascending Order
for ((i = 0; i < ${#arr[@]}; i++)); do
    for ((j = i + 1; j < ${#arr[@]}; j++)); do
        if [ ${arr[i]} -gt ${arr[j]} ]; then
            temp=${arr[i]}
            arr[i]=${arr[j]}
            arr[j]=$temp
        fi
    done
done
echo "Array in Ascending Order: ${arr[@]}"

# Descending Order
for ((i = 0; i < ${#arr[@]}; i++)); do
    for ((j = i + 1; j < ${#arr[@]}; j++)); do
        if [ ${arr[i]} -lt ${arr[j]} ]; then
            temp=${arr[i]}
            arr[i]=${arr[j]}
            arr[j]=$temp
        fi
    done
done
echo "Array in Descending Order: ${arr[@]}"



# Count Even and Odd Numbers in an Array
arr=(10 15 20 25 30)
even=0
odd=0
for i in "${arr[@]}"; do
    if [ $((i % 2)) -eq 0 ]; then
        even=$((even + 1))
    else
        odd=$((odd + 1))
    fi
done
echo "Even numbers count: $even"
echo "Odd numbers count: $odd"
