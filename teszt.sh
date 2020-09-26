#!/bin/bash

rm -f results.txt

./a.out units/Sally.txt units/Maple.txt
./a.out units/Sally.txt units/Alduin.txt
./a.out units/Maple.txt units/Alduin.txt
./a.out units/Maple.txt units/Sally.txt
./a.out units/Alduin.txt units/Sally.txt
./a.out units/Alduin.txt units/Maple.txt

DIFF=$(diff results.txt outputs.txt)


if [ "$DIFF" != "" ]
then
	echo "The results and output file are different!"
fi
