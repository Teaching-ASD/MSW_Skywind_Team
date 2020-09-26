#!/bin/bash

rm results.txt

./a.out Sally.txt Maple.txt
./a.out Sally.txt Alduin.txt
./a.out Maple.txt Alduin.txt
./a.out Maple.txt Sally.txt
./a.out Alduin.txt Sally.txt
./a.out Alduin.txt Maple.txt

