#!/bin/bash
command g++ B17EE013.cpp
n=10

while [ $n -lt 60 ]
do
    for(( i=0 ; i<10 ; i++ ))
    do
        command ./a.out $n
    done
    ((n=n+10))
done

command python plot.py
