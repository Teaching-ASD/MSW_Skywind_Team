#!/bin/bash

rm -f result.txt

./a.out units/Sally.txt units/Maple.txt
./a.out units/Sally.txt units/Alduin.txt
./a.out units/Maple.txt units/Alduin.txt
./a.out units/Maple.txt units/Sally.txt
./a.out units/Alduin.txt units/Sally.txt
./a.out units/Alduin.txt units/Maple.txt

DIFF=$(diff result.txt outputs.txt)


if [ "$DIFF" != "" ]
then
	echo "The result and test file are different!"
fi
