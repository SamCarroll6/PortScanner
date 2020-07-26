#!/bin/bash

gcc -c *.c

gcc *.o

./a.out $1

rm *.o
rm a.out 
