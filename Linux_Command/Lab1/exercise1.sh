#!/bin/bash

echo "Enter your name :"
read name

echo "Enter your age :"
read age

current_year=2026

echo "Name : $name , Age : $age Year :$((current_year - age))"

#or
read -p "Enter your name : " name1
read -p "Enter your age : " age1

echo "Name : $name1 , Age : $age1 , Birth Year : $((current_year - age1))"