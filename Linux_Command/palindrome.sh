#!/bin/bash

echo "Enter a word:" 
read word 
reverse=""
length=${#word} 
for (( i=length-1; i>=0; i-- )); do 
 reverse="$reverse${word:i:1}" 
done 
if [ "$word" = "$reverse" ]; then 
 echo "$word is a palindrome" 
else 
 echo "$word is not a palindrome" 
fi
