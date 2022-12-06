#!/bin/sh
cc 06_random.c -o createrand -lm
echo "128" > read.dat
./createrand < read.dat
