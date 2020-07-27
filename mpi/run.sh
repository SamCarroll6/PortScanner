#!/bin/bash

mpicc -c main.c ps.c

mpicc -o main *.o

mpirun -np $1 ./main $2

rm *.o
rm main