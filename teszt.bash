#!/bin/bash

rm results.txt

cd units

Files=()

for file in *.json
    do
        Files+=($file)
    done

cd ..

for file in ${Files[*]}
    do
        for file2 in ${Files[*]}
        do
            if [ $file != $file2 ]
                then ./a.out $file $file2
            fi
        done
    done