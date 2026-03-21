#!/bin/bash

g++ gen.cpp -o gen -O2
g++ std.cpp -o brute -O2
g++ 1.cpp -o fast -O2

for ((i=1;i<=10000;i++))
do
    echo "Test $i"

    ./gen > input.txt
    ./brute < input.txt > brute.txt
    ./fast < input.txt > fast.txt

    if diff brute.txt fast.txt
    then
        echo "OK"
    else
        echo "WA on test $i"
        echo "Input:"
        cat input.txt
        echo "Brute:"
        cat brute.txt
        echo "Fast:"
        cat fast.txt
        break
    fi
done