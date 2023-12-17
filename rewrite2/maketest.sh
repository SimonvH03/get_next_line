#!/bin/bash
make -C ../../libft -s all clean
mv ../../libft/libft.a ./
cc *.c libft.a -o test.a
./test.a
rm test.a