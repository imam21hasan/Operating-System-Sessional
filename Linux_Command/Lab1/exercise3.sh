#!/bin/bash

for i in {1..20}; do
    if [ $((i % 2)) = 0 ]; then
        echo "$i is Even"
    else
        echo "$i is Odd"
    fi
done

for i in {1..20}; do
    if [ $((i % 3)) = 0 ]; then
        echo "$i is multiple of 3."
    fi
done
